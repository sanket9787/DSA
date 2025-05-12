// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

//This code uses extra space

class Solution {
public:
    void getAns(int ind, vector<int>& arr, int target, set<vector<int>> &ans, vector<int> &temp){
        if(ind >= arr.size()){
            if(target == 0){
                ans.insert(temp);
                return;
            }
            return;
        }
            if(arr[ind] <= target){
                temp.push_back(arr[ind]);
                getAns(ind+1, arr, target - arr[ind], ans, temp);
                temp.pop_back();
            }
            
            getAns(ind+1 ,arr, target, ans, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        int ind = 0;

        sort(arr.begin(), arr.end());
        getAns(ind, arr, target, ans, temp);
    
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};


//Without extra space 

