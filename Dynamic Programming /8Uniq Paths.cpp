//Recursion and memoisation

class Solution {
public:
    int getAns(int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n==0) return 1;
        if(n<0 || m<0) return 0;
        if(dp[m][n] != -1) return dp[m][n];

        int left = getAns(m,n-1,dp);
        int up = getAns(m-1,n,dp);

        return dp[m][n] = left + up;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int ans = getAns(m-1,n-1,dp);
        return ans;
    }
};

// Tabulation

class Solution {
public:

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n,0));

        dp[0][0] = 1;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
               int right = 0;
               int up = 0;

               //Need to take this if because there are two ways to go to 1,1 from 0,0.
               //so we cant start from i = 1 , j = 1. Because dp[1][0] dp[0][1] also should return 1. so we have to start from i , j = 0;
               
               if(i ==0 && j == 0) dp[i][j] = 1;
               else{

                if( j-1 >= 0 ) right = dp[i][j-1];
                if( i-1 >= 0) up = dp[i-1][j];

                dp[i][j] = right + up;

               }
            }
        }

        return dp[m-1][n-1];
    }
};

// Space optimisation
class Solution {
public:

    int uniquePaths(int m, int n) {
        
        vector<int> prev(n,0);
        vector<int> curr(n,0);

    prev  0         0
    curr  0,0 (1)   0,1 (1)
          1,0      1,1
          2,0      2,1
    
    //for 0,0  1,0  2,0 assign  value 1. so that for each next value of the current row will be 
    //able to assing value of previous of curr array.
    //up value for the current element will be prev[j] i.e same index as the current column

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){

               int left = 0;
               int up = 0;
               
               // Only one way from index j = 0 to reach to 0,0. 
               // Assign it at every first element of row. 
               // curr[0,0] = 1; curr[1,0] = 1.. 
               // so that first element of each row gets value 1. and while traversing 
               // the row we will be able to assing left = curr[j-1]; (for j > 0)
               
               if(j == 0) curr[j] = 1;
               else{

                if( j-1 >= 0 ) left = curr[j-1];

                //for the up element we need same index as of current column(j) from the prev array
                if( i-1 >= 0) up = prev[j];

                curr[j] = left + up;

               }
               //assign prev = curr out side else becuase what if the row has only one element.
               //in this cas it wont come into else condition, will execute only this line if(j == 0) curr[j] = 1;
               prev = curr;
               //cout << curr[j] << " ";
            }
            //cout << endl;
        }

        return prev[n-1];
    }
};
