//Recursion 

class Solution {
public:
    bool getAns(int i, int j, string s, string p){

        if(i < 0 && j < 0) return true;
        if(i >= 0 && j < 0) return false;
        if(j >= 0 && i < 0){
            for(int ii = 0; ii<= j; ii++){
                if(p[ii] != '*') return false;
            }
            return true;
        }

        if(s[i] == p[j] || p[j] == '?') return getAns(i-1, j-1, s, p);
        if(p[j] == '*') return getAns(i-1, j, s, p) || getAns(i, j-1, s, p);

        return false;
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
    
        return getAns(m, n, s, p);
    }
};

//memoisation with 1 based indexing
class Solution {
public:
    bool getAns(int i, int j, string s, string p, vector<vector<int>> &dp){

        if(i < 0 && j < 0) return true;
        if(i >= 0 && j < 0) return false;
        if(j >= 0 && i < 0){
            for(int ii = 0; ii<= j; ii++){
                if(p[ii] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = getAns(i-1, j-1, s, p, dp);
        if(p[j] == '*') return dp[i][j] = getAns(i-1, j, s, p, dp) || getAns(i, j-1, s, p, dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return getAns(m, n, s, p, dp);
    }
};