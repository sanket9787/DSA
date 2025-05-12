//recursion and memoisation

#include <bits/stdc++.h> 
int getSum(vector<int> &arr, int target,int ind, vector<vector<int>> &dp){
    if(ind == 0){
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || arr[0] == target) return 1;
        return 0;
    }
    
    if(dp[ind][target] != -1) return dp[ind][target];
    int notTake = getSum(arr, target, ind -1, dp);
    int take = 0;
    if(arr[ind] <= target) take = getSum(arr, target-arr[ind], ind-1, dp);

    return dp[ind][target] = take + notTake;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(int i =0; i<n; i++){
        sum += arr[i];
    }
    
    
    // sum - s2 - s2 = d
    // sum - 2s2 = d
    int target = (sum - d)/2;

    if(sum - d < 0 || (sum-d)%2 != 0) return false;
    vector<vector<int>> dp(n, vector<int>(target+1,-1));

    int ind = n-1;
    return getSum(arr, target, ind,dp);
}


//Tabulation

#include <bits/stdc++.h> 

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(int i =0; i<n; i++){
        sum += arr[i];
    }
       
    // sum - s2 - s2 = d
    // sum - 2s2 = d
    int target = (sum - d)/2;

    if(sum - d < 0 || (sum-d)%2 != 0) return false;
    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
    }

    if(arr[0] == 0) dp[0][0] = 2;
    else if(arr[0] <= target) dp[0][arr[0]] = 1;

    for(int ind = 1; ind<n; ind++){
        for(int t = 0; t<=target; t++){

            int notTake = dp[ind-1][t];
            int take = 0;
            if(arr[ind] <= t) take = dp[ind-1][t-arr[ind]];

            dp[ind][t] = take + notTake;
        }
    }
    
    return dp[n-1][target];
}


