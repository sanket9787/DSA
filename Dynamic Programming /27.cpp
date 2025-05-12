



//Tabulation
#include <bits/stdc++.h>

int lcs(string &str1, string &str2){
    // Write your code here.
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    int maxi = INT_MIN;
    for(int i = 1; i<= m; i++){
        for(int j = 1; j<=n ; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                if(dp[i][j] > maxi) maxi = dp[i][j];
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    return maxi;
}

//Space 
#include <bits/stdc++.h>

int lcs(string &str1, string &str2){
    // Write your code here.
    int m = str1.length();
    int n = str2.length();
    
    vector<int> curr(n+1,0), prev(n+1,0);

    int maxi = INT_MIN;
    for(int i = 1; i<= m; i++){
        for(int j = 1; j<=n ; j++){
            if(str1[i-1] == str2[j-1]){
                curr[j] = 1 + prev[j-1];
                if(curr[j] > maxi) maxi = curr[j];
            }else curr[j] = 0;
        }
        prev = curr;   
    }

    return maxi;
}