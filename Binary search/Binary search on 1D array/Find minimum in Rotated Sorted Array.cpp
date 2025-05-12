class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        int n = nums.size();
        int min = nums[0];

        //using l <= h becuase what if lowest is the last number during binary search in that case l = h = mid. so need to traverse until l<= h
        while(l<=h){
            int mid = (l+h)/2;

            //using nums[mid] >= nums[l] becuase what if mid and low pointing to the same position hence if not used equal to sign it will go to else if condition and will do h = mid - 1, this can cause h to be lesser than zero. for example arr = [2 , 1];    here  l = 0, h = 1, mid = 0.

            //if left half is sorted assign nums[low] to min and move to right half 
            if(nums[mid] >= nums[l]){
                if(min > nums[l]) min = nums[l];      
                l = mid + 1;

            //if right half is sorted assign nums[mid] to low and move to left half
            }else if(nums[mid] <= nums[h]){
                if(min > nums[mid]) min = nums[mid];
                h = mid - 1;
            }

        }

        return min;
    }
};