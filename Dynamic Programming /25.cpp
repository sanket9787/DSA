//recursion and memoisation
//0 based indexing
class Solution {
public:
    int getAns(string s1, string s2, int i, int j, vector<vector<int>>&dp){
        //if any index reached lesser than zero means no string to compare just return 0.
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //if both index i and j are same then add 1 to the anwer and go to previous index for
        //both i and j 
        if(s1[i] == s2[j]){
            return 1 + getAns(s1, s2, i-1, j-1,dp);
        }
        //if not same then go first i - 1, j  then  i, j- 1 . And get maximum out of this two.
        else return dp[i][j] = max( getAns(s1,s2, i-1, j,dp), getAns(s1, s2, i, j-1,dp) );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.length();
        int j = text2.length();
        vector<vector<int>>dp (i, vector<int>(j,-1));
        int ans = getAns(text1, text2, i-1, j-1, dp);

        return ans;
    }
};

//for tabulation 
//without shifting indexes 
//Gives wrong answer 

class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        string s1 = text1;
        string s2 = text2;

        vector<vector<int>>dp (text1.length(), vector<int>(text2.length(),0));

        bool a = false;
        for(int j = 0; j < text2.length(); j++){
            if(text1[0] == text2[j]){
                dp[0][j] = 1;
                a = true;
            } 
            //Need to do this becuase if we found we have a match then for next all index of j in dp array there should be 1. becuase in all index after that in text2 there will be 1 match with the text1 or 1st letter of text1.
            if(a == true) dp[0][j] = 1;
            cout<< dp[0][j] <<" ";
        }
        cout << endl;

        for(int i = 1; i< text1.length(); i++){
            for(int j = 0; j< text2.length(); j++){
                
                if(s1[i] == s2[j]){
                    //Here if we dont follow the approach of shifting the index we have to deal with this following senario
                    // As we are starting from j = 0 we need to check if j-1 >= 0 if not we have to take dp value from above row only that is dp[i-1][j];
                   if(j-1>=0) dp[i][j] = 1 + dp[i-1][j-1];
                   else dp[i][j] = 1 + dp[i-1][j];
                }  
                else {
                    if(j-1>=0){
                        dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
                    }
                    else dp[i][j] = max( dp[i-1][j], dp[i][j] );
                }

                cout << dp[i][j] << " ";
            }
            cout << endl;          
        }
        
        return dp[text1.length()-1][text2.length()-1];
    }
};

//Shifting index
//Recursion and memoisation

class Solution {
public:
    int getAns(string s1, string s2, int i, int j, vector<vector<int>>&dp){
       
        if(i == 0 || j == 0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //as shifted the index only for checking in string do i-1 and j-1  
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 1 + getAns(s1, s2, i-1, j-1,dp);
        }
        else return dp[i][j] = max( getAns(s1,s2, i-1, j,dp), getAns(s1, s2, i, j-1,dp) );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.length();
        int j = text2.length();
        vector<vector<int>>dp (i+1, vector<int>(j+1,-1));
        int ans = getAns(text1, text2, i, j, dp);

        return ans;
    }
};

//Tabulation:
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>>dp (n+1, vector<int>(m+1,0));
        
        // as already declared vector with all zero value no need to do the base case thing again.
        // make it i <= n as we now have shifted the index we will be storing n+1, m+1 in dp as well.
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){

                //as shifted the index only for checking in string do i-1 and j-1  
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1] );
            }
        }

        return dp[n][m];
    }
};

//Space optimisation
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){

                //as shifted the index only for checking in string do i-1 and j-1  
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else curr[j] = max(prev[j] , curr[j-1]);
            }
            prev = curr;
        }

        return prev[m];
    }
};