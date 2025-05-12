class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        /* As we have already taken care of edgecases else this will be reuslt 
        in overflow error because what if in example nums[] = [3,4,3,2,1].  
        low = mid = arr[0] = 3 and  high = nums[1] = 4. In this case we will try 
        to access nums[mid - 1] which will cause overflow. */

        int high = n-2;
        int low = 1;
        int ans;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
                 ans = mid;
                 break;
            }

            if(nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }else if(nums[mid] < nums[mid - 1] && nums[mid] > nums[mid + 1]) high = mid - 1;
            else low = mid + 1;

        }

        return ans;
    }
};