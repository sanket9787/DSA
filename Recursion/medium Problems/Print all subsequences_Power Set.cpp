class Solution {
public:
    void getSubsets(vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp, int cnt){
        if(cnt >= nums.size()){
            ans.push_back(temp);
            return;
        }
        int num = nums[cnt];
        temp.push_back(num);
        getSubsets(nums,ans,temp,cnt+1);
        temp.pop_back();

        getSubsets(nums, ans, temp, cnt+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int cnt = 0;
        getSubsets(nums,ans, temp, cnt);

        return ans;
    }
};