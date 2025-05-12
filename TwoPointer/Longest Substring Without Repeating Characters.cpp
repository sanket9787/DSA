class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxlength = 0;
        int l = 0;

        for(int r = 0; r < s.length(); r++){
            if(mp.find(s[r]) != mp.end()){

                /* taking max between l and mp[s[r]]+1 because what if l now is in middle of the 
                array and now at r(which is obviously ahead of l) we found out element at r has 
                occurred at the start of the array (before the l) if not taken 
                max between l and mp[s[r]] + 1, l will move again behind at the start of the 
                array where we have found the maching of element at r poition. 
                Example : "abba" 

                when r = 3, l = 2. mp[s[r]] = 0 (previous occurence of a) and then l = mp[s[r]] + 1 -> l = 0 + 1 = 1 and 
                then maxlenght will become  r - l + 1 = 3 - 1 + 1 = 3 which is wrong. */

                l = max(l, mp[s[r]] + 1);
            }

            mp[s[r]] = r;
            maxlength = max(maxlength, r - l + 1);
            cout << r << " " << l <<endl;
        }
        

        return maxlength;
    }
};


//Better optimal approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int maxlength = 0;
        int l = 0;
        int n = s.length();
        int r = 0;

        while(r < n){
            if(hash[s[r]] != -1 ){
                l = max(l, hash[s[r]] + 1);
            }

            hash[s[r]] = r;
            maxlength = max(maxlength, r - l + 1);
            r++;
            //cout << r << " " << l <<endl;
        }
        

        return maxlength;
    }
};