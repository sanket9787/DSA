class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];

                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string ans = "";
        
        int i = m;
        int j = n;
        
        while(i>0 && j>0){
            //If both the elements are same then push one of them in ans string go digonally up
            if(str1[i-1] == str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;

        //        0 1 2 3
        //          c a b
        //   0    0 0 0 0
        //   1 a  0 
        //   2 b  0
        //   3 a  0
        //   4 c  0

            //If dp[i-1][j] > dp[i][j-1] then there is no point in going towards dp[i][j-1] becuase in that path we wont find the case for both elements same. As this is how we have constructed the dp. Now we are moving up the row so need to add the element from first string str1. str1 is on the y axis. push_bac(str1[i-1]);  this is the ith elment but used i-1 becuase of 1 based indexing.
         
            }else if(dp[i-1][j] > dp[i][j-1]){
                //we are adding from str1 so taken ith index.
                ans.push_back(str1[i-1]);
                i--;

            } else{
                //now we are adding element from str2 so need to take jth index.
                ans.push_back(str2[j-1]);
                j--;
            }
        }

        //fill up the remaining elements      
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }

        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};