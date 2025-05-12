class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        int ans = nums[0];
        int n = nums.size();

        if(n == 1) return ans;
        if(nums[0] != nums[1]) return ans;
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        while(l <= h){
            int mid = (l + h)/ 2;
            //cout << "mid = " << mid << " ";
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid +1]){
                ans = nums[mid];
                break;
            }

            if(mid%2 == 0){
                //cout << "mid in if = " << mid << " ";
                if(nums[mid + 1] == nums[mid]) l = mid + 1;
                else if(nums[mid - 1] == nums[mid]) h = mid - 1;
            }else{
                if(nums[mid - 1] == nums[mid]) l = mid + 1;
                else if(nums[mid + 1] == nums[mid]) h = mid - 1;
            }
            
        }

        return ans;
    }
};