//recursion and memoisation
class Solution {
public:
    int getAns(vector<vector<int>>& grid, int m, int n,vector<vector<int>> &dp){
    
        if(m == 0 && n==0) return grid[m][n];
        if(m < 0 || n<0 ) return 1e8;
        if(dp[m][n] != -1) return dp[m][n];

        int up = grid[m][n] + getAns(grid,m-1,n,dp);
        int left = grid[m][n] + getAns(grid,m,n-1,dp);
        //cout << "m,n = " << m <<" "<< n << endl;
        //cout << min(up,left)<<endl;
        return dp[m][n] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        int ans = getAns(grid,m-1,n-1,dp);

        return ans;
    }
};

// Tabulation:
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int up = 1e8, left = 1e8;

                    if(i-1 >=0) up = grid[i][j] + dp[i-1][j];
                    if(j-1 >=0) left = grid[i][j] + dp[i][j-1];

                    dp[i][j] = min(up,left);
                }   
            }
        }

        return dp[m-1][n-1];

    }
};

//Space Optimisation
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //vector<vector<int>> dp(m, vector<int> (n,0));

        vector<int> curr(n,0);
        vector<int> prev(n,0);

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i==0 && j==0) curr[j] = grid[i][j];
                else{
                    int left = 1e8, up = 1e8;

                    //for the first row up value is not there so do the i-1>=0
                    if(i-1>=0) up = grid[i][j] + prev[j];
                    if(j-1 >=0) left = grid[i][j] + curr[j-1];

                   curr[j] = min(up,left);
                }   
            }
            prev = curr;
        }

        return prev[n-1];

    }
};