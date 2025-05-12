//Recursion

class Solution {
public:
    // f(i,j) represents how many operations does it take to convert s1 to s2 from ith to jth index.
    int getAns(int i, int j, string s1, string s2){

        //base case if both i and j less than zero means we have converted s1 to s2 hence no need to perform any operation hence return 0.
        if(i < 0 && j < 0) return 0;

        // if i < 0 and j>=0 means s2 still have some elements left. so need to insert j+1 elements from string s2 to s1 hence return j+1.
        if(i < 0 && j >= 0) return j+1;

        //if i>=0 means exhausted string s2 and still elements left in s1. hence need to delete i+1 elements from start of string s1.
        if(i >= 0 && j < 0) return i+1;

        if(s1[i] == s2[j]){
            // here adding to 0 becuase both are same and hence do not need to perform any operation.
            return 0 + getAns(i-1, j-1, s1, s2);
        }

        //here adding 1 because in all 3 cases we are performing one operation so that s1 convert to s2.
        return 1 + min(
            //h o r s e     r o s
            //0 1 2 3 4     0 1 2

            //case for insert a charater
            //i = 4, j = 2. here insert means inserting s2[j] into s1 due to which other elements in s1 will shift to left i will remain same. now both elements match at s1 and s2. I will remain same as we have added element after ith position. jth index will move to j-1.
            getAns(i, j-1, s1, s2),

            //case for delete a character
            //for eg i = 3, j = 1. here we will delete i = 3. hence all element will shift right, that means hypothetically we will move i to i-1. 
            min( getAns(i-1, j, s1, s2),

            //case for replace
            //if we replace ith element eqal to jth element of s2 both will become same and hece we will go i-1, j-1.
            getAns(i-1, j-1, s1, s2)
    
            ));
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        return getAns(m, n, word1, word2);
    }
};

//Memoisation
//Converted to 1 based indexing 

class Solution {
public:
    
    int getAns(int i, int j, string s1, string s2, vector<vector<int>> &dp){

        if(i == 0 && j == 0) return 0;
        //****IMP***: as converted to 1 based indexing instead of returning j+1 and i+1 return i and j.
        if(i == 0 && j > 0) return j;
        if(i > 0 && j == 0) return i;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 0 + getAns(i-1, j-1, s1, s2, dp);
        }
        //else condition if dont match
        return dp[i][j] = 1 + min(
            getAns(i, j-1, s1, s2, dp),
            min( getAns(i-1, j, s1, s2, dp), getAns(i-1, j-1, s1, s2, dp))
            );
    }

    int minDistance(string word1, string word2) {

        int m = word1.length();
        int n = word2.length();
        //Edge case :
        if(m == 0) return n;
        if(n == 0) return m;

        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));

        return getAns(m, n, word1, word2, dp);
    }
};

// Tabulation

class Solution {
public:

    int minDistance(string s1, string s2) {

        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int j = 1; j<=n; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i<=m; i++){
            dp[i][0] = i;
        }

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){

                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                }
                else{     
                    dp[i][j] = 1 + min(
                        dp[i][j-1],
                        min( dp[i-1][j] , dp[i-1][j-1] )
                        );
                }

            }
        }

        return dp[m][n];
    }
};

// Space Optimisation
class Solution {
public:

    int minDistance(string s1, string s2) {

        int m = s1.length();
        int n = s2.length();

        vector<int> prev(n+1,0), curr(n+1, 0);
        //cout << prev[0]<< " ";

        for(int j = 1; j<=n; j++){
            prev[j] = j;
            //cout << prev[j] << " ";
        }
        //cout << endl;

        for(int i = 1; i<=m; i++){
            curr[0] = i;
            //cout << curr[0] << " ";
            for(int j = 1; j<=n; j++){

                if(s1[i-1] == s2[j-1]){
                    curr[j] = 0 + prev[j-1];
                }
                else{     
                    curr[j] = 1 + min(
                        curr[j-1],
                        min( prev[j] , prev[j-1] )
                        );
                }
                //cout << curr[j] << " ";
            }
            //cout << endl;
            prev = curr;
        }

        return prev[n];
    }
};


// for tabulation
       e x e c u t i o n
     0 1 2 3 4 5 6 7 8 9 
  i  1 1 2 3 4 5 6 6 7 8 
  n  2 2 2 3 4 5 6 7 7 7 
  t  3 3 3 3 4 5 5 6 7 8 
  e  4 3 4 3 4 5 6 6 7 8 
  n  5 4 4 4 4 5 6 7 7 7 
  t  6 5 5 5 5 5 5 6 7 8 
  i  7 6 6 6 6 6 6 5 6 7 
  o  8 7 7 7 7 7 7 6 5 6 
  n  9 8 8 8 8 8 8 7 6 5 

// for space optimisatoin : error was coming
//reason was did not prev = curr;
0 1 2 3 4 5 6 7 8 9 
1 1 2 3 4 5 6 6 7 8 
2 1 2 3 4 5 6 7 8 8 
3 1 2 3 4 5 5 6 7 8 
4 0 1 2 3 4 5 6 7 8 
5 1 2 3 4 5 6 7 8 8 
6 1 2 3 4 5 5 6 7 8 
7 1 2 3 4 5 6 6 7 8 
8 1 2 3 4 5 6 7 7 8 
9 1 2 3 4 5 6 7 8 8 