// Memoisation

bool getSum(vector<int> &arr, int sum, int ind, vector<vector<int>>& dp){
 
        if(sum == 0) return true;
        if(ind == 0) return arr[0] == sum;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        bool take = false;
        if(arr[ind]<=sum) take = getSum(arr,sum-arr[ind], ind-1, dp);
       
        bool notTake = getSum(arr,sum, ind-1, dp);
        
        return dp[ind][sum] = (take || notTake);
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int ind = arr.size();
        int mysum = 0;
        vector<vector<int>>dp(arr.size(), vector<int>(sum+1, -1));
        bool ans = getSum(arr, sum, ind-1, dp);
        
        return ans;
    }

//Tabulation 

bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int ind = arr.size();
        int n = ind;
        int mysum = 0;
        vector<vector<int>>dp(arr.size(), vector<int>(sum+1, false));
       // bool ans = getSum(arr, sum, ind-1, dp);
        
        //base case 
        //if the target is zero then index at which the true value will be there is from 0 to n-1 
        //
        for(int i = 0; i< n; i++){
            dp[i][0] = true;
        }
        
        // if 0the index is lesser than equal to the given target (sum) then assign the dp 
        //array whose target is = arr[0] as true;
        // So in the first row of the dp array first value 0,0 that is index is zero and target is 
        // zero will be true and the second one which is 0th row and target is equal to arr[0] will 
        // be true; This means that if the first element is equal to the given target at that point 
        // then its possible to achieve that target so we are assinging the true value at that index 
        //in dp array
        if(arr[0] <= sum){
            dp[0][arr[0]] = true;
        }
        
        //Now first row of dp array is filled up so take ind = 1 and target = 1
        // in the first row (ind = 1) of dp array we will check if it is possible to achieve target = 1 to sum
        // by taking the current index element from the array or not taking the current index.
        // if we take it we will check the dp value of the last row and target value will be target-arr[ind]
        // if we dont take the current index then check for dp[ind-1][target]
        
        for(int ind = 1 ; ind < n; ind++){
            for(int target = 1; target <= sum ; target++){
                
                bool take = false;
                if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]];
                
                bool notTake = dp[ind-1][target];
                
                dp[ind][target] = (take || notTake);
                
            }
        }
        
        return dp[n-1][sum];
    }


// Space Optimisation 

bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int ind = arr.size();
        int n = ind;
        int mysum = 0;
        vector<vector<int>>dp(arr.size(), vector<int>(sum+1, false));
        
        vector<int> prev(sum+1, false);
        vector<int> curr(sum+1, false);
        
        
       // assign the first elelemt of dp array as true because when the sum or target is zero that index 
       //should be true.
        prev[0] = true;
        //assigning curr[0] = true, because when in for loop we assing prev = curr, false value will get assign to it from declared curr array.
        curr[0] = true;
        
        if(arr[0] <= sum){
            prev[arr[0]] = true;
        }
        
        for(int ind = 1 ; ind < n; ind++){
            
            for(int target = 1; target <= sum ; target++){
                
                bool take = false;
                if(arr[ind]<=target) take = prev[target-arr[ind]];
                
                bool notTake = prev[target];
                
                curr[target] = (take || notTake);
                
            }
            prev = curr;
        }
        
        return prev[sum];
    }