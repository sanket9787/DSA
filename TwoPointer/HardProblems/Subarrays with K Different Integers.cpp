class Solution {
public:
    int func1(vector<int>&nums, int k){
        if(k < 0) return 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int count = 0;
        unordered_map<int,int>map;

        while(r < n){
            map[nums[r]]++;
            while(map.size() > k){
                map[nums[l]]--;
                if(map[nums[l]] == 0) map.erase(nums[l]);
                l++;
            }
            count = count + r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func1(nums, k) - func1(nums, k - 1);
    }
};

/*Now if we clearly look at the constraints its given as : 
Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length

so we cane optimie this code further by using vector instead of map

*/

class Solution {
public:
    int func1(vector<int>&nums, int k){
        if(k < 0) return 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int count = 0;
        //vector size is giving as nums.size() + 1 because in constrainst 1 <= nums[i], k <= nums.length, for eg nums = [1,2] here size is 2 but element is also 2 which we cannot store if vector size is nums.size().
        vector<int> v(nums.size() + 1, 0);
        int distinct = 0;

        while(r < n){
            if(v[nums[r]] == 0) distinct++;
            v[nums[r]]++;
            while(distinct > k){
                v[nums[l]]--;
                if(v[nums[l]] == 0) distinct--;
                l++;
            }
            count = count + r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func1(nums, k) - func1(nums, k - 1);
    }
};