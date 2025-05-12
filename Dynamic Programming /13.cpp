//Recursion and Memoisation 
int getAns(int r,int c1,int c2, vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        
        if(c1>=grid[0].size() || c1<0 || c2>=grid[0].size() || c2<0) return 1e-8;
        if(r==grid.size()-1 && c1==c2) return grid[r][c1];
        if(r==grid.size()-1 && c1!=c2) return grid[r][c1]+grid[r][c2];
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        
        int maxi = INT_MIN;
        
        for(int i = -1; i<=1; i++){
            for(int j = -1; j<=1; j++){
                int ans;
                if(c1==c2) ans = grid[r][c1] + getAns(r+1,c1+i,c2+j,grid,dp);
                else ans = grid[r][c1] + grid[r][c2] + getAns(r+1, c1+i,c2+j,grid,dp);
                maxi = max(maxi,ans);
            }
        }
        
        return dp[r][c1][c2] = maxi;
    }
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
       int r = 0;
       int c1 = 0;
       int c2 = grid[0].size()-1;
       vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
       int ans = getAns(r,c1,c2,grid,dp);
       return ans;
       
    }

//Tabulation;

int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
       int r = 0;
       int c1 = 0;
       
       int c2 = grid[0].size()-1;
       vector<vector<vector<int>>> dp(n, vector<vector<int>>(m , vector<int>(m , 0)));
       
       // first storing the elements at the last row of dp. this row will contain m cross m elements.
       // this is because we want multiple combinations of selecting c1, c2 elements from the last row
       // and that count will be m square two for loops. for eg. if m = 3, then dp array will store 9 
       //elements in each row each element representing the sum of values at the index c1, c2.
       //if the c1 == c2 then we will only take one value in dp array of grid[n-1][c1];
       // for this we will require the 3d array dp[r][c1][c2]
       
       for(int c1 = 0; c1<m; c1++){
           for(int c2 = 0; c2<m; c2++){
              if(c1==c2) dp[n-1][c1][c2] = grid[n-1][c1];
              else dp[n-1][c1][c2] = grid[n-1][c1] + grid[n-1][c2];
              //cout << dp[n-1][c1][c2] << " ";
           }
       }
       
       //cout << endl;
      
      // We have filled up the first row of the dp array which is from the elements of the last row (n-1)
      //of the given grid array, this is because here we are following bottom-top approach way 
      //now rest needs to fill up. so we will start from the n-2 row. 
      
      for(int r = n-2; r>=0; r--){
           
          for(int c1 = 0; c1 < m; c1++){
               
              for(int c2 = 0; c2 < m; c2++){
                   
                  int maxi = INT_MIN;
                   
                  for(int i = -1; i<=1; i++){
                    for(int j = -1; j<=1; j++){
                        int ans = 1e-8;
                        if(c1+i >= 0 && c1+i < m && c2+j >=0 && c2 + j < m){
                            if(c1==c2) ans = grid[r][c1] + dp[r+1][c1+i][c2+j];
                            else ans = grid[r][c1] + grid[r][c2] + dp[r+1][c1+i][c2+j];
                        }
                        
                        maxi = max(maxi,ans);
                     }
                    }
                    
                dp[r][c1][c2] = maxi;
                //cout << dp[r][c1][c2] << " ";
              }
          }
          //cout << endl;
      }
     
      return dp[0][0][m-1];
    
       
}

// Space Optimisation :

int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
       int r = 0;
       int c1 = 0;
       
       int c2 = grid[0].size()-1;
       vector<vector<int>>curr(m , vector<int>(m , 0));
       vector<vector<int>>next(m , vector<int>(m , 0));
       
       for(int c1 = 0; c1<m; c1++){
           for(int c2 = 0; c2<m; c2++){
              if(c1==c2) next[c1][c2] = grid[n-1][c1];
              else next[c1][c2] = grid[n-1][c1] + grid[n-1][c2];
              //cout << dp[n-1][c1][c2] << " ";
           }
       }
       
      //cout << endl;
      
      for(int r = n-2; r>=0; r--){
           
          for(int c1 = 0; c1 < m; c1++){
               
              for(int c2 = 0; c2 < m; c2++){
                   
                  int maxi = INT_MIN;
                   
                  for(int i = -1; i<=1; i++){
                    for(int j = -1; j<=1; j++){
                        int ans = 1e-8;
                        if(c1+i >= 0 && c1+i < m && c2+j >=0 && c2 + j < m){
                            if(c1==c2) ans = grid[r][c1] + next[c1+i][c2+j];
                            else ans = grid[r][c1] + grid[r][c2] + next[c1+i][c2+j];
                        }
                        
                        maxi = max(maxi,ans);
                     }
                    }
                    
                curr[c1][c2] = maxi;
                //cout << dp[r][c1][c2] << " ";
              }
          }
          next = curr;
          //cout << endl;
      }
     
      return next[0][m-1];   
    }   
}