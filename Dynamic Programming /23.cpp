//Recursion and memoisation 
#include <bits/stdc++.h>
int getAns(int ind , int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(ind == 0){
        if(weight[0] <= w) return (w/weight[0]) * profit[0];
        return 0;
    }

    if(dp[ind][w] != -1) return dp[ind][w];

    int notPick = 0 + getAns(ind-1, w, profit, weight, dp);
    int pick = INT_MIN;
    if(weight[ind] <= w) pick = profit[ind] + getAns(ind, w-weight[ind], profit, weight, dp);

    return dp[ind][w] = max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    int ans = getAns(n-1, w, profit, weight, dp);
    
    return ans;
}

//Tabulation

#include <bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w+1, 0));

    //for index i = 0, we will have weights from 0 to w. hence need to fill first
    //row of dp table.
    
    for(int i = 0; i <= w; i++){
       if(weight[0] <= i) dp[0][w] = (i/weight[0]) * profit[0];
    }

    for(int ind = 1; ind < n ; ind++){
        for(int j = 1; j <= w; j++){
            int notPick = 0 + dp[ind-1][j];
            int pick = INT_MIN;
            if(weight[ind] <= j) pick = profit[ind] + dp[ind][j-weight[ind]];

            dp[ind][j] = max(pick, notPick);
        }
    }
    
    return dp[n-1][w];
}

//Space optimisation:

#include <bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int> prev(w+1, 0);
    vector<int> curr(w+1, 0);

    //for index i = 0, we will have weights from 0 to w. hence need to fill first
    //row of dp table.

    for(int i = 0; i <= w; i++){
       if(weight[0] <= i) prev[w] = (i/weight[0]) * profit[0];
    }

    curr = prev;

    for(int ind = 1; ind < n ; ind++){
        for(int j = 0; j <= w; j++){
            int notPick = 0 + prev[j];
            int pick = INT_MIN;
            if(weight[ind] <= j) pick = profit[ind] + curr[j-weight[ind]];

            curr[j] = max(pick, notPick);
        }
        prev = curr;
    }
    
    return prev[w];
}