class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        vector<vector<int>> next(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));

        for(int ind = n-1; ind >= 0; ind--){
            for(int prev = 1; prev >= 0; prev--){
                for(int count = k-1; count >= 0; count--){
                    
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