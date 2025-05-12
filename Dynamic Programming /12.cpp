class Solution {
public:
    int getSum(vector<vector<int>>& matrix, int m, int n, vector<vector<int>> &dp){

        if(n>=matrix.size()|| n<0) return 1e8;
        if(m == 0 ) return matrix[m][n];
        if(dp[m][n] != -1) return dp[m][n];

        int mini = INT_MAX;
        //There are three ways we can go up n-1,n,n+1,
        for(int i = -1; i<=1 ; i++){
            int up = matrix[m][n] + getSum(matrix, m-1,n+i,dp);
            mini = min(up,mini);
        }
        
        return dp[m][n] = mini;      
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m;
        int mini = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n,-1));

        //calculate the min value from all element of the last row
        for(int i = n; i>0;i--){
            int ans = getSum(matrix, m-1,i-1,dp);
            mini = min(ans, mini);
        }
        
        return mini;
    }
};

//space optimisation
class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m;
        int mini = INT_MAX;
        //vector<vector<int>> dp(m, vector<int>(n,0));

        vector<int> curr(m,0);
        vector<int> prev(m,0);

        for(int i = 0; i<m ; i++){
            prev[i] = matrix[0][i];
        }

        for(int i = 1;i<m; i++){ 
    
            for(int j=0; j<n; j++){
                int mini = INT_MAX;

                for(int k = -1; k<=1; k++){
                  int up = 1e8;
                  if(j+k<m && j+k>=0) up = matrix[i][j] + prev[j+k];
                    mini = min(up,mini);
                }
            
                curr[j] = mini;
            }
            prev = curr;    
        }

        int ans = INT_MAX;
        for(int i = 0; i< m; i++){
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};