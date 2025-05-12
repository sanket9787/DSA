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

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        int getSame = longestCommonSubsequence(word1, word2);
        return m + n - 2*getSame;
    }
};