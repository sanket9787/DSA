//recursion working but cant memoise this into dp 
class Solution {
public:
    int getAns(int ind, string s, string t, string temp){
        if(ind < 0){
            if(temp == t) return 1;
            return 0;
        }

        int pick = getAns(ind-1, s, t, temp+s[ind]);
        int notPick = getAns(ind-1, s, t, temp);

        return pick + notPick;
    }
    int numDistinct(string s, string t) {
        string temp = "";
        int ind = s.length();
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return getAns(ind-1, s2, t, temp);
    }
};

//recursion

class Solution {
public:
    // 0 1 2 3 4 5 6        
    // b a b g b a g
    
    // 0 1 2
    // b a g

    //Here each f(i, j) recursion call represents number of ways to generate string t from s from ith index of string s and jth index of string t.
    int getAns(int i, int j, string s, string t){
        
        if(j < 0) return 1;
        if(i < 0 && j >= 0) return 0;

        if(s[i] == t[j]){
           //If both string matches then go to i-1 and j-1
           //do the next recursion call go to i-1 keeping the j same,So I want to get the another t[j] in string s.
           // Add both of this recursion 
           return getAns(i-1, j-1, s, t) + getAns(i-1, j, s, t);
        }
        
        //If string does not match just go i-1 keeping the j same. Just go and find out the number of ways for i-1 and j th index.
        return getAns(i-1, j, s, t);

    }
    int numDistinct(string s, string t) {
       
        int i = s.length();
        int j = t.length();

        return getAns(i-1, j-1, s, t);
    }
};

//Memoistion and converted to 1 based indexing 

class Solution {
public:
    
    int getAns(int i, int j, string s, string t, vector<vector<int>> &dp){
        
        if(j == 0) return 1;
        if(i == 0 && j > 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]){      
           return dp[i][j] = getAns(i-1, j-1, s, t, dp) + getAns(i-1, j, s, t, dp);
        }
         
        return dp[i][j] = getAns(i-1, j, s, t, dp);

    }

    int numDistinct(string s, string t) {
       
        int i = s.length();
        int j = t.length();
        vector<vector<int>> dp(i+1, vector<int>(j+1, -1));

        return getAns(i, j, s, t, dp);
    }
};

//Tabulation 

class Solution {
public:

    int numDistinct(string s, string t) {
       
        int m = s.length();
        int n = t.length();
        //double is used because of singed integer overflow
        vector<vector<double>> dp(m+1, vector<double>(n+1, 0));
        
        //Make all the values where j == 0 for all i from 0 to m. Means all the elements in string t are covered.
        for(int i = 0; i<= m; i++){
            dp[i][0] = 1;
        }

        //Make zeros where we have reached the 0th index in s string but there still some few elements left in string t i.e j>0 
        for(int j = 1; j<=n; j++){
            dp[0][j] = 0;
        }

        for(int i = 1; i<= m ; i++){
            for(int j = 1; j<= n ; j++){
                if(s[i-1] == t[j-1]){      
                   dp[i][j] = dp[i-1][j-1] +  dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[m][n]; 
    }
};

// Space Optimisation 

class Solution {
public:

    int numDistinct(string s, string t) {
       
        int m = s.length();
        int n = t.length();
        
        vector<double> prev(n+1, 0) , curr(n+1, 0);
        
        prev[0] = 1;
        
        //Not necessary added just for understanding
        // for(int j = 1; j<=n; j++){
        //     prev[j] = 0;
        // }

        // Do this becuase when we assing prev = curr, 0 will get assing in first index of prev
        // which is wrong it should be 1.
        curr[0] = 1;

        for(int i = 1; i<= m ; i++){
            for(int j = 1; j<= n ; j++){
                if(s[i-1] == t[j-1]){      
                  curr[j] = prev[j-1] +  prev[j];
                }
                else curr[j] = prev[j];
            }
            prev = curr;
        }

        return prev[n]; 
    }
};