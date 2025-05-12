
void fillDp1(vector<int> &dp, vector<int>& nums){
	int n = nums.size();
	int maxi = 1;

	for(int ind = 0; ind < n; ind++){
		for(int j = 0; j<ind; j++){

			if(nums[j] < nums[ind]){

				dp[ind] = max(dp[ind] , 1 + dp[j]);
	
			}
		
		}
		
	}
}

void fillDp2(vector<int> &dp, vector<int>& nums){
	int n = nums.size();
	int maxi = 1;

	for(int ind = n-1; ind >=0 ; ind--){
		for(int j = n-1; j>ind; j--){

			if(nums[j] < nums[ind]){

				dp[ind] = max(dp[ind] , 1 + dp[j]);
	
			}
		
		}
		
	}
	
}

int longestBitonicSubsequence(vector<int>& nums, int n)
{
	// Write your code here.
	vector<int> dp1(n,1), dp2(n,1);
	fillDp1(dp1, nums);
	fillDp2(dp2, nums);

	// for(int i = 0 ; i< nums.size(); i++){
	// 	cout << dp1[i] << " " << dp2[i] << endl;
	// }
	int maxi = 1;
	int i = 0;
	while(i < nums.size()){
		maxi = max(maxi, dp1[i] + dp2[i] - 1);
		i++;
	}
	return maxi;
}
