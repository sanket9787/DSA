Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

//extra space 
class Solution {
public:
    void getAns(int ind, vector<int>& nums, vector<int>&temp, set<vector<int>> &ans){
        if(ind >= nums.size()){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        getAns(ind+1,nums,temp,ans);
        temp.pop_back();
        getAns(ind+1,nums,temp,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        int ind = 0;
        getAns(ind, nums, temp, ans);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};