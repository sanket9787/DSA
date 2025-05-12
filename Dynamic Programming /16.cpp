// Memoisation
// This approach works but 

class Solution {
public:
    bool getAns(int ind, vector<int>& nums, int target,vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return nums[ind] == target;
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool notPick = getAns(ind-1, nums, target, dp);
        bool pick = false;
        if(nums[ind]<=target) pick = getAns(ind-1, nums, target-nums[ind], dp);

        return dp[ind][target] = pick || notPick;
    }

    int minimumDifference(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        //get the total sum first from the nums array
        for(int i = 0; i < n; i++){
            sum = sum+nums[i];
        }

        //creat a dp array of sie of nums array that is n rows and colums sie sum+1 so that as to
        // store the sum number as well in the dp array;
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        
        int ind = n-1;
        //now take the target from 0 to the target as sum. And check if this target is possible in the 
        //current nums array.
        //The last row of the dp array will store the bool value that if it is possible to achieve the given
        // target in the nums array.
        for(int target = 0; target <= sum ; target++){
            bool ansbool = getAns(ind,nums,target,dp);
        }

        // Now as we have the information of what targets are possible from 0 to sum 
        // due to this we did not have to carry the second sum2. because it can be calculated vial sum - sum1.
        // where sum1 is the dp[n-1][target];
        // so when sum1 = sum that means array1 have all the element and array2 have 0 element.

        int minDiff = INT_MAX;
        for(int target = 0 ; i <= sum; i++){
           int sum1 = dp[n-1][target];
           int sum2 = sum - sum1;
           if(abs(sum1-sum2) < minDiff) minDiff = abs(sum1-sum2);
        }

        return minDiff;

    }
};


//space

class Solution {
public:

    int minimumDifference(vector<int>& arr) {
        

        int n = arr.size();
        int totSum = 0;
        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }

        // Initialize a boolean vector 'prev' to represent the previous row of the DP table
        vector<bool> prev(totSum + 1, false);

        // Base case: If no elements are selected (sum is 0), it's a valid subset
        //prev[0] = true;
        if (n == 0) return 0;
        // Initialize the first row based on the first element of the array
        if (arr[0] <= totSum)
            prev[arr[0]] = true;

        // Fill in the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            // Create a boolean vector 'cur' to represent the current row of the DP table
            vector<bool> cur(totSum + 1, false);
            cur[0] = true;

            for (int target = 1; target <= totSum; target++) {
                // Exclude the current element
                bool notTaken = prev[target];

                // Include the current element if it doesn't exceed the target
                bool taken = false;
                if (arr[ind] <= target)
                    taken = prev[target - arr[ind]];

                cur[target] = notTaken || taken;
            }

            // Set 'cur' as the 'prev' for the next iteration
            prev = cur;
        }

        int mini = 1e9;
        for (int i = 0; i <= totSum; i++) {
            if (prev[i] == true) {
                // Calculate the absolute difference between two subset sums
                int diff = abs(i - (totSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;

    }
};