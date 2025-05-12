
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]

class Solution {
public:
    void getAns(int ind, vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp, int target){
        //Base case : if the index reached equal to or more than size of array now if the target is reduced to 
        //zero then push the temp array into the answer. If target is not reduced to zero then just
        // return to previous function call.
        if(ind >= nums.size()){
            if(target == 0){
                ans.push_back(temp);
                return;
            }
            return;
        }
        
        if(nums[ind] <= target){
            temp.push_back(nums[ind]);
            getAns(ind, nums, ans, temp, target - nums[ind]);
            temp.pop_back();
        }

        // If the target is smaller than nums[ind] then dont pick the element from nums array
        // just move the index to next position and do the above recursion call again until the target becomes zero
        getAns(ind+1, nums, ans, temp, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int ind = 0;
        getAns(ind, nums, ans, temp, target);

        return ans;
    }
};