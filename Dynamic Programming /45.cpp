#include <bits/stdc++.h>
class Solution {
public:

    static bool compare(string s1, string s2){
        cout << s1 << " and " << s2 << " result = "; 
        if(s1.size() != s2.size() + 1) return false;
        int i = 0, j = 0;
        while(i < s1.size()){
            if(s1[i] == s2[j]) {
                i++;
                j++;
            }else i++;
        }
        if(i == s1.size() && j == s2.size()) return true;
        return false;
    }

    static bool comp(string s1, string s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        int maxi = 1;
        int lastIndInDp = 0;

        for(int i = 0; i<n; i++){
            hash[i] = i;
            for(int j = 0; j < i; j++){
                bool result = compare(words[i], words[j]);
                cout << result << endl;
                if( result && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
        
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastIndInDp = i;
            }
        }


        return maxi;
    }
};