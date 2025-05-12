//Recursion and memoisation

class Solution {
public:
    int getAns(vector<int> & coins , int am, int n, vector<vector<int>> &dp){
        if(n == 0){
            //if the target is dived by 0th index element then return target/coins[ind]
            if(am % coins[n] == 0) return am/coins[n];
            // if not then return maximum element it means its not possible so in min(pick, notpick) it will not take this 0th index.
            else return 1e9;
        }

        if(dp[n][am] != -1) return dp[n][am];

        int notPick = 0 + getAns(coins, am, n-1, dp);
        int pick = 1e9;
        //if we are picking the current index it means we are adding that to the sum to reach the target or amount so we will add 1 + recursioncall.
        if(coins[n] <= am) pick = 1 + getAns(coins, am-coins[n], n, dp);

        return dp[n][am] = min(notPick, pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        int ans = getAns(coins, amount, n-1, dp);

        if(ans == 1e9) return -1;
        else return ans;
        
    }
};

//Tabulation

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, 0));
        
        //for target = 0 to amount, fill up the 0th row of the dp with forllowing logic.
        for(int t = 0; t<= amount; t++){
            if(t % coins[0] == 0) dp[0][t] = t /coins[0];
            else dp[0][t] = 1e9;
        }
        
        for(int i = 1; i< n; i++){
            for(int t = 0; t<=amount; t++){

                int notPick = 0 + dp[i-1][t]; 
                int pick = INT_MAX;
               
                if(coins[i] <= t) pick = 1 + dp[i][t-coins[i]];

                dp[i][t] = min(notPick, pick);
            }
        }
        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        else return ans;
        
    }
};