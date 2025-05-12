//Recursion and memoisation: 

class Solution {
public:
    int getAns(vector<int>& nums,int ind, vector<int> &dp){
        if(ind==0)return nums[0];
        if(ind<0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + getAns(nums,ind-2,dp);
        int notpick = 0 + getAns(nums,ind-1,dp);

        return dp[ind] = max(pick,notpick);
    }

    int rob(vector<int>& nums){

        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        int n = nums.size() - 2;
        // it is similar to dont pick the adjacent that is pick up the ind - 2 element
        //but here it is a circle so create two arrays having 1st and second last
        // and second and last element

        vector<int> nums1(nums.begin()+1,nums.end());
        vector<int> nums2(nums.begin(),nums.end()-1);
    
        vector<int>dp(n+1, -1);
       int first = getAns(nums1,n,dp);

       vector<int>dp2(n+1, -1);
       int second = getAns(nums2,n,dp2);

       return max(first , second);
    }

};

//Tabulation:

class Solution {
public:
    
    int getAns(vector<int>& nums, vector<int> &dp){
        dp[0] = nums[0];
        
        for(int i = 1; i<nums.size();i++){

           int pick = INT_MIN;
           if(i-2<0) pick = nums[i];
           else pick = nums[i] + dp[i-2];

           int notpick = INT_MIN;
           if(i-1>=0) notpick = 0 + dp[i-1];
           
           dp[i] = max(pick, notpick);
        }

        return dp[nums.size()-1];
    }


    int rob(vector<int>& nums){

        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        int n = nums.size() - 2;
        // it is similar to dont pick the adjacent that is pick up the ind - 2 element
        //but here it is a circle so create two arrays having 1st and second last
        // and second and last element

        vector<int> nums1(nums.begin()+1,nums.end());
        vector<int> nums2(nums.begin(),nums.end()-1);
    
        vector<int>dp(n+1, -1);
        int first = getAns(nums1,dp);

        vector<int>dp2(n+1, -1);
        int second = getAns(nums2,dp2);

        return max(first , second);
    }

};


//Space optimisation