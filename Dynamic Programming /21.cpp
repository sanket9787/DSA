//Recursion and memoisation

class Solution {
public:

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

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int i =0; i<n; i++){
            sum += nums[i];
        }
        
        int target2 = (sum - target)/2;

        if(sum - target < 0 || (sum-target)%2 != 0) return false;
        vector<vector<int>> dp(n, vector<int>(target2+1,-1));

        int ind = n-1;
        return getSum(nums, target2, ind,dp);
    }
};

// Tabulation

class Solution {
public:

    int findTargetSumWays(vector<int>& arr, int d) {
        // Write your code here.
        int n = arr.size();
        int sum = 0;
        for(int i =0; i<n; i++){
            sum += arr[i];
        }
        
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
};

// Space Optimisation

class Solution {
public:

    int findTargetSumWays(vector<int>& arr, int d) {
        // Write your code here.
        int n = arr.size();
        int sum = 0;
        for(int i =0; i<n; i++){
            sum += arr[i];
        }
        
        int target = (sum - d)/2;

        if(sum - d < 0 || (sum-d)%2 != 0) return false;

        vector<int> curr(target+1, 0);
        vector<int> prev(target+1, 0);

        for (int i = 0; i < n; i++) {
                prev[0] = 1;
        }

        if(arr[0] == 0) prev[0] = 2;
        else if(arr[0] <= target) prev[arr[0]] = 1;

        curr = prev;

        for(int ind = 1; ind<n; ind++){
            for(int t = 0; t<=target; t++){

                int notTake = prev[t];
                int take = 0;
                if(arr[ind] <= t) take = prev[t-arr[ind]];

                curr[t] = take + notTake;
            }
            prev = curr;
        }
        
        return prev[target];
    }
};
