//Recursion and memoisation 

class Solution {
public:
    bool getAns(vector<int>& nums,int target, int ind, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return nums[ind] == target;
        if(dp[ind][target] != -1) return dp[ind][target];

        bool notPick = getAns(nums,target,ind-1,dp);
        bool pick = false;
        if(nums[ind]<=target) pick = getAns(nums, target-nums[ind], ind-1, dp);

        return dp[ind][target] = notPick || pick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(auto &it : nums){
            sum = sum + it;
        }

        if(sum%2 == 1) return false;
        int target = sum/2; 
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        
        int ans = getAns(nums, target, n-1, dp);

        return ans;
    }
};


//Tabulation
   bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(auto &it : nums){
            sum = sum + it;
        }

        if(sum%2 == 1) return false;
        int target = sum/2; 
        vector<vector<int>> dp(n, vector<int>(target+1,false));
        

        for(int i = 0; i<n;i++){
            dp[i][0] = true;
        }

        if(nums[0]<= target){
            dp[0][nums[0]] = true;
        }

        for(int ind = 1; ind < n; ind++){
            for(int j = 1; j<=target; j++){

                bool notPick = dp[ind-1][j];
                bool pick = false;
                if(nums[ind]<=j) pick = dp[ind-1][j-nums[ind]];

                dp[ind][j] = notPick || pick;
            }
        }

        return dp[n-1][target];
    }


// Space Optimisation
