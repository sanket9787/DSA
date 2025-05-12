class Solution {
public:
    //This soultion is working here becuase when I am finding number of subarrays with k <=3 I am considering posibility that the subarray wont contain the odd number means k = 0. Example subarray [2]. 
    //Same thing doing while finding subarrays with k <= 3 - 1. so when we are subtracting both of them we are elimineting that subarray [2].
    int func(vector<int>& nums, int k){

        if(k<0) return 0;
        int l = 0; 
        int r = 0;
        int n = nums.size();
        int count = 0;
        int anscount = 0;

        while(r < n){
            if(nums[r]%2 != 0) count++;
            while(count > k){
                if(nums[l]%2 != 0) count--;
                l++;
            }
            anscount = anscount + r-l+1;
            r++;
        }
        //cout << anscount << " ";
        return anscount;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int c1 = func(nums, k);
        int c2 = func(nums, k - 1);
        return c1 - c2;
    }
};