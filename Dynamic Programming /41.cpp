//Recursion 
class Solution {
public:
    int getAns(int ind, vector<int> & nums, int prev){

        if(ind == nums.size()) return 0;
        int len1 = 0;
        int len2 = 0;
        //pick current index with condition, 
        //IF pick current index then current index will become prev for the next one
        if(prev == -1 || nums[ind] > nums[prev]){
            len1 = 1 + getAns(ind+1, nums, ind);
        }
        //not pick the current index
        //if not pick previous index remains prev 
        len2 = 0 + getAns(ind + 1, nums, prev);
        
        return max(len1, len2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int ind = 0;
        
        return getAns(ind, nums, prev);
    }
};

//memoisation 
class Solution {
public:

    int getAns(int ind, vector<int> & nums, int prev_ind, vector<vector<int>> &dp){

        if(ind == nums.size()) return 0;
        int len1 = 0;
        int len2 = 0;

        //shifting the prev_index 
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len1 = 1 + getAns(ind+1, nums, ind, dp);
        }
        
        len2 = 0 + getAns(ind + 1, nums, prev_ind, dp);
        
        return dp[ind][prev_ind+1] = max(len1, len2);
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev_ind = -1;
        int ind = 0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return getAns(ind, nums, prev_ind, dp);
    }
};

//Tabulation
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int len1 = 0;
        int len2 = 0;

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int ind = 0; ind < n; ind++){
            for(int j = 0; j<=ind; j++){

                if(nums[j] < nums[ind]){

                    dp[ind] = max(dp[ind] , 1 + dp[j]);
                    if(dp[ind] > maxi){
                        maxi = dp[ind];
                    }

                }
            }
        }

        return maxi;
    }
};