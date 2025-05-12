//Recursion and memoisation

class Solution {
public:

    int getAns(int amount, vector<int> & coins, int ind, vector<vector<int>> &dp){
        if(ind == 0){
            //if last index is dividing the amount then we can form array only with last index hence following line.
            if(amount % coins[ind] == 0) return 1;
            return 0;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notPick = getAns(amount, coins, ind-1, dp);
        int pick = 0;
        if(coins[ind] <= amount) pick = getAns(amount - coins[ind], coins, ind, dp);

        return dp[ind][amount] = notPick + pick;
    }

    int change(int amount, vector<int>& coins) {
        int ind = coins.size();
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

        int ans = getAns(amount, coins, ind-1, dp);
        return ans;
    }
};

// Tabulation
//This code giving TLE 
class Solution {
public:

    int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<long>> dp(coins.size(), vector<long>(amount+1, 0));

    for(int i = 0 ; i<= amount; i++){
        if(i % coins[0] == 0) dp[0][i] = 1;
    }
    
    for(int ind = 1 ; ind < n; ind++){
        for(int target = 0; target <= amount ; target++){
            long notPick = dp[ind-1][target];
            long pick = 0;
            if(coins[ind] <= target) pick = dp[ind][target - coins[ind]];

            dp[ind][target] = notPick + pick;
        }
    }

    return dp[n-1][amount];
}

};

//Space optimisation
//This code giving TLE 
class Solution {
public:

    int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<long>> dp(coins.size(), vector<long>(amount+1, 0));
    vector<long> curr(amount+1, 0);
    vector<long> prev(amount+1, 0);

    for(int i = 0 ; i<= amount; i++){
        if(i % coins[0] == 0) prev[i] = 1;
    }
    
    curr = prev;

    for(int ind = 1 ; ind < n; ind++){
        for(int target = 0; target <= amount ; target++){
            long notPick = prev[target];
            long pick = 0;
            if(coins[ind] <= target) pick = curr[target - coins[ind]];

           curr[target] = notPick + pick;
        }
        prev = curr;
    }

    return prev[amount];
}

};