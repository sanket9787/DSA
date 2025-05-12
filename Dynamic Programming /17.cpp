//recursion and memoisation:

    int getAns(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        //if(target == 0) return 1;
        if(ind == 0) {
            if(target == 0 && arr[0] == 0) return 2; // two subsets: pick and not pick
            if(target == 0 || arr[0] == target) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int notTake = getAns(ind-1,target,arr, dp);
        int take = 0;
        
       if(arr[ind] <= target) take = getAns(ind-1,target-arr[ind], arr, dp);
        
        return dp[ind][target] = notTake + take;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int ind = arr.size();
        vector<vector<int>> dp(ind, vector<int>(target+1,-1));
        int ans = getAns(ind-1, target, arr,dp);
        
        return ans;
    }


// Tabulation:

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
    
        // Base case initialization
        // There's always 1 way to form sum 0 - the empty subset
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        
        // Handle first element
        if(arr[0] == 0) dp[0][0] = 2;
        else if (arr[0] <= target) dp[0][arr[0]] = 1;
        
        // Fill the dp table
        for (int i = 1; i < n; i++) {
            //take j from zero as we are changing dp[0][0] = 2 if arr[0] = 0, so remaining dp[i][0] will also get change hence need to take the j = 0 as well.
            for (int j = 0; j <= target; j++) {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (arr[i] <= j) {
                    take = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = notTake + take;
            }
        }
        
        return dp[n - 1][target];
    }

// Space Optimisation :

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        //vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);
        // Base case initialization
        // There's always 1 way to form sum 0 - the empty subset
        
        prev[0] = 1;
        //no need to assing curr[0] = 1 as we are starting from j = 0 in for loop, so curr[0] will be handled in this case
        // Handle first element
        if(arr[0] == 0) prev[0] = 2;
        else if (arr[0] <= target) prev[arr[0]] = 1;
        
        // Fill the dp table
        for (int i = 1; i < n; i++) {
            //take j from zero as we are changing dp[0][0] = 2 if arr[0] = 0, so remaining dp[i][0] will also get change hence need to take the j = 0 as well.
            
            for (int j = 0; j <= target; j++) {
                int notTake = prev[j];
                int take = 0;
                if (arr[i] <= j) {
                    take = prev[j - arr[i]];
                }
                curr[j] = notTake + take;
            }
            
            prev = curr;
        }
        
        return prev[target];
    }