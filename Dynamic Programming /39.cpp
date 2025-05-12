class Solution {
public:
    int getAns(int ind, bool prev, vector<int>& prices, vector<vector<int>> &dp){
        
        if(ind >= prices.size()) return 0;
        if(dp[ind][prev] != -1) return dp[ind][prev];

        int profit = 0;
        if(prev){
           profit = max(-prices[ind] + getAns(ind+1, false, prices, dp), 
                         0  + getAns(ind+1, true, prices, dp)
                    );
        }
        if(!prev){
            profit = max( prices[ind] + getAns(ind+2, true, prices, dp), 
                      0 + getAns(ind+1, false, prices, dp)
                    );
        }

        return dp[ind][prev] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int ind = 0;
        bool prev = true;
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return getAns(ind, prev, prices, dp);
    }
};

//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        bool prev = true;

        // laset row of dp ind = n, will be zero this vector definetion handles this base case
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        int profit = 0;
        for(int ind = n-1; ind>=0; ind--){
            for(int prev = 0; prev <= 1; prev++){
                
                if(prev){
                profit = max(-prices[ind] + dp[ind+1][false], 
                                0  + dp[ind+1][true]
                            );
                }
                else {
                    profit = max( prices[ind] + dp[ind+2][true] , 
                            0 + dp[ind+1][false]
                            );
                }

                dp[ind][prev] = profit;
            }
        }
        
        return dp[0][1];
    }
};