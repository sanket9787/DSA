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

    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        //The number of min insertions will be the number of elements dont match with the reverse of the given string
        return s.length() - longestCommonSubsequence(s, s2);
    }
};