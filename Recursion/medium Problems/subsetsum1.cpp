Given a array arr of integers, return the sums of all subsets in the list.  
Return the sums in any order.

Examples:

Input: arr[] = [2, 3]
Output: [0, 2, 3, 5]
Explanation: When no elements are taken then Sum = 0. 
When only 2 is taken then Sum = 2. When only 3 is taken then Sum = 3. 
When elements 2 and 3 are taken then Sum = 2+3 = 5.


void getSum(int ind, int sum, vector<int>& arr, vector<int>& ans){
        if(ind >= arr.size()){
            ans.push_back(sum);
            return;
        }
        getSum(ind+1, sum + arr[ind], arr, ans);
        getSum(ind+1, sum, arr, ans);

    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int sum = 0;
        int ind = 0;
        vector<int> ans;
        
        getSum(ind, sum, arr, ans);
        
        return ans;
    }