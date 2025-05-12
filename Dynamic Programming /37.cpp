//recursion

class Solution {
public:
    //here cant do count+1 in if(prev) section, cause transaction wont complete. it will finish
    //in at the second transaciton buy state only cuase when count == 2, this buy stock(pick) function at 
    // if(prev) will get in return 0 as cnt == 2,  -prices[ind] + 0, 
    int getAns(int ind, bool prev, int count, vector<int>& prices){
        if(ind == prices.size() || count == 2 ) return 0;
    
        int profit = 0;
        if(prev){
           profit = max(-prices[ind] + getAns(ind+1, false, count, prices), 
                         0  + getAns(ind+1, true, count, prices)
                    );            
        }

        if(!prev){
            profit = max( prices[ind] + getAns(ind+1, true, count+1, prices), 
                      0 + getAns(ind+1, false, count, prices)
                    );
        }

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        bool prev = true;
        int n = 0;
        int count = 0;

        return getAns(n, prev, count, prices);
    }
};

//memoisation
class Solution {
public:

    //here cant do count+1 in if(prev) section, cause transaction wont complete. it will finish
    //in at the second transaciton buy state only cuase when count == 2, this buy stock(pick) function at 
    // if(prev) will get in return 0 as cnt == 2,  -prices[ind] + 0, 
    int getAns(int ind, bool prev, int count, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(ind == prices.size() || count == 2 ) return 0;
        if(dp[ind][prev][count] != -1) return dp[ind][prev][count];

        int profit = 0;
        if(prev){
           profit = max(-prices[ind] + getAns(ind+1, false, count, prices, dp), 
                         0  + getAns(ind+1, true, count, prices, dp)
                    );            
        }

        if(!prev){
            profit = max( prices[ind] + getAns(ind+1, true, count+1, prices, dp), 
                      0 + getAns(ind+1, false, count, prices, dp)
                    );
        }

        return dp[ind][prev][count] = profit;
    }

    int maxProfit(vector<int>& prices) {
        bool prev = true;
        int n = prices.size();
        int ind = 0;
        int count = 0;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return getAns(ind, prev, count, prices, dp);
    }
};

//Tabulation:

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int profit = 0;

        //here need to make count size as 3 becuase in dp it will try to find dp[ind][prev][2]
        // but for prev its not the case its not looking for prev+1 anything like that.
        // And for ind we are starting from n-1 so it will be searching for n-1 + 1, which can be stored in dp of n+1 size.
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int ind = n-1; ind >= 0; ind--){
            for(int prev = 1; prev >= 0; prev--){
                for(int count = 1; count >= 0; count--){
                    
                    if(prev){
                    profit = max(-prices[ind] + dp[ind+1][false][count],
                                    0  + dp[ind+1][true][count]
                                );            
                    }

                    else if(!prev){
                        profit = max( prices[ind] + dp[ind+1][true][count+1],
                                0 + dp[ind+1][false][count]
                                );
                    }

                    dp[ind][prev][count] = profit;
                }
            }
        }
        
        //returning dp[0][1][0]. prev means buying state as 1 becuase we are buying first initially. so final answer will be storing in that state.
         return dp[0][1][0];
    }
};

//Space optimisation
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int profit = 0;

        vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int prev = 1; prev >= 0; prev--){
                for(int count = 1; count >= 0; count--){
                    
                    if(prev){
                    profit = max(-prices[ind] + next[false][count],
                                    0  + next[true][count]
                                );            
                    }

                    else if(!prev){
                        profit = max( prices[ind] + next[true][count+1],
                                0 + next[false][count]
                                );
                    }

                    curr[prev][count] = profit;
                }
                next = curr;
            }
        }

        //returning dp[0][1][0]. prev means buying state as 1 becuase we are buying first initially. so final answer will be storing in that state.
         return next[1][0];
    }
};
