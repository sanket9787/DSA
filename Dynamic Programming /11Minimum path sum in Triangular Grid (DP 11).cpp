class Solution {
public:
    int getSum(vector<vector<int>>& triangle, int m, int n,vector<vector<int>> &dp){
        if(m == triangle.size()-1) return triangle[m][n];
        if(dp[m][n] != -1) return dp[m][n];

        int down = triangle[m][n] + getSum(triangle, m+1,n,dp);
        int diag = triangle[m][n] + getSum(triangle, m+1,n+1,dp);

        return dp[m][n] = min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = 0;
        int n = 0;
        int s = triangle.size();
        vector<vector<int>> dp(s,vector<int>(s,-1));
        int ans = getSum(triangle, m, n,dp);
        
        return ans;
    }
};

//Tabulation:
int minimumTotal(vector<vector<int>>& triangle) {
        int m = 0;
        int n = 0;
        int s = triangle.size();

        vector<vector<int>> dp(s,vector<int>(s,-1));
        
        for(int i = 0;i<triangle.size();i++){
            dp[s-1][i] = triangle[s-1][i];
        }
        
        for(int i = s-2; i>=0; i--){
            for(int j = i; j>=0;j--){

                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,diag);
            }
        }
        return dp[0][0];
    }

//Space Optimisation:
