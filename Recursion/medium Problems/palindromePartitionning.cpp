// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

class Solution {
public:
    bool checkPalindrome(string str){
        int l = 0; 
        int r = str.length()-1;
        while(l<r){
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void getAns(int ind, string s, vector<vector<string>> &ans, vector<string> &temp){
        //Here in this code when we are reaching end of the string it means we have partitioned the string because even if lets say some part of the string is not palindrome then we are partitioning the string to the single element. so this base case ind >= s.length is sufficient. we can put the temp into answer.
        if(ind >= s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < s.size(); i++){
            string str = s.substr(ind, i - ind + 1);
            if(checkPalindrome(str)){

                temp.push_back(str);
                getAns(i + 1, s, ans, temp);
                temp.pop_back();
            }
        }
        
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        int ind = 0;
        getAns(ind, s, ans, temp);

        return ans;
    }
};