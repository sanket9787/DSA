class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            vector<int> dp(n, 1);
            vector<int> hash(n, 0);
            int maxi = 1;
            int lastIndInDp = 0;
    
            for(int i = 0; i<n; i++){
                hash[i] = i;
                for(int j = 0; j < i; j++){
                    if( nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]){
                        dp[i] = 1 + dp[j];
                        hash[i] = j;
                    }
                }
                if(maxi < dp[i]){
                    maxi = dp[i];
                    lastIndInDp = i;
                }
            }
    
            vector<int> ans;
            ans.push_back(nums[lastIndInDp]);
    
            while( hash[lastIndInDp] != lastIndInDp ){
                lastIndInDp = hash[lastIndInDp];
                ans.push_back(nums[lastIndInDp]);
            }
    
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };