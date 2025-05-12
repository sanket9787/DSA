class Solution {
public:
    // int getAns(vector<int>&nums, int n, vector<int> &dp){
    //     if(n<0) return 0;
    //     if(n == 0) return nums[0];
    //     if(dp[n] != -1) return dp[n];     

    //     return dp[n] = max(pick,notpick);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int> dp(n, 0);

        //return getAns(nums,n-1,dp);

        dp[0] = nums[0];
        //if(n>1) dp[1] = nums[1];

        for(int i = 1; i < n; i++){
            int pick = INT_MIN;

            // for edge case arr= [1,2]
            if(i-2 < 0) pick = nums[i] + 0;
            else{
                pick = nums[i] + dp[i-2];
            }
        
            int notpick = 0 + dp[i-1];

            dp[i] = max(pick, notpick);
        }

        return dp[n-1];
    }
};


//Tabulation:

class Solution {
public:
    // int getAns(vector<int>&nums, int n, vector<int> &dp){
    //     if(n<0) return 0;
    //     if(n == 0) return nums[0];
    //     if(dp[n] != -1) return dp[n];     

    //     return dp[n] = max(pick,notpick);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev1 = nums[0];
        int prev2 = 0;
        int curr = 0;

        for(int i = 1; i < n; i++){
            
            int pick = nums[i];
            // for edge case arr= [1,2]
            if(i >= 2) pick = nums[i] + prev2;                
        
            int notpick = 0 + prev1;

            curr = max(pick, notpick);
            prev2 = prev1;
            prev1 = curr;
            
        }

        //we can return curr as well but what if array size is one then we 
        //wont go into for loop thats why return prev1.
        return prev1;
    }
};