class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.length();
        int maxi = 0;
        map<char, int> map;
        int maxcount = 0;

        //aabbbacccabb
        while(r<n){
            map[s[r]]++;
            maxcount = max(maxcount, map[s[r]]);
            if((r-l+1) - maxcount > k){
                map[s[l]]--;
                l++;
            }
            maxi = max(maxi, r-l+1);
            r++;
        }

        return maxi;
    }
};