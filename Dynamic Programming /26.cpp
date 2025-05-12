
#include <bits/stdc++.h>
string findLCS(int n, int m,string &s1, string &s2){
	

	vector<vector<int>>dp (n+1, vector<int>(m+1,0));
        
    for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){

			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else dp[i][j] = max(dp[i-1][j] , dp[i][j-1] );
		}
	}

	string ans = "";
	int i = n;
	int j = m;

	//To print the sequence in dp table we have to look if the ith and jth index element
	//match for s1 and s2. if they do add the element in ans. if not means both elements are
	//different then check from which index we got the value in of current dp[i][j]. As the 
	//main logic was if the elements dont match then we take the maximum of max(dp[i-1][j] , dp[i][j-1]).
	//So just do reverse here. So we will move towards maxmimum value between dp[i-1][j] , dp[i][j-1] as 
	// " This will lead us to the element which are equal in both string"
	while(i > 0 && j > 0){
		if(s1[i-1] == s2[j-1]){
				ans.push_back(s1[i-1]);
				i = i - 1;
				j = j - 1;
		}else if(dp[i-1][j] > dp[i][j-1]){
			i = i-1;
		}else j = j-1;
	}
	reverse(ans.begin(), ans.end());
	return ans;	
}