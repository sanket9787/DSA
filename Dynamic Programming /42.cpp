#include <bits/stdc++.h>
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here

	vector<int> dp(n, 1);
	vector<int> hash(n, 0);
	int maxi = 1;
	int lastIndInDp = 0;

	for(int i = 0; i<n; i++){
		hash[i] = i;
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i] && 1 + dp[j] > dp[i]){
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
	ans.push_back(arr[lastIndInDp]);

	while( hash[lastIndInDp] != lastIndInDp ){
		lastIndInDp = hash[lastIndInDp];
		ans.push_back(arr[lastIndInDp]);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
