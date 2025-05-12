class Solution {
public:
    int func1(vector<int>& nums, int goal){
        //edge case where goal is 0 then goal - 1 = -1 returnig zero works for goal - 1 because when we are doing func1 - func1(goal - 1) we are finding for example if we want weight of person = 70kg so we will find total persons with weight lesser than equal to 70 - total person weight <= 69. Here we are doing it until zero so when goal is zero there is no lesser value than zero. so only func1(nums, goal) will give the outpout.
        if(goal < 0) return 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int count = 0;
        int sum = 0;

        while(r < n){
            sum = sum + nums[r];

            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }

            count = count + r - l + 1;
            r++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return func1(nums, goal) - func1(nums, goal - 1); 
    }
};