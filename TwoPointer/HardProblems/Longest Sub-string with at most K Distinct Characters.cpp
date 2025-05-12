#include <bits/stdc++.h>
int getLengthofLongestSubstring(int k, string s)
{
   // Write your code here.
   int r = 0;
   int l = 0;
   int n = s.length();
   int Maxlength = 0;
   map<char,int> map;

   while(r < n){
      map[s[r]]++;
      while(map.size() > k){
         map[s[l]]--;
         if(map[s[l]] == 0) map.erase(s[l]);
         l++;
      }
      int len = r-l + 1;
      if(Maxlength < len) Maxlength = len;
      r++;
   }

   return Maxlength;
}


//Optimal code :

#include <bits/stdc++.h>
int getLengthofLongestSubstring(int k, string s)
{
   // Write your code here.
   int r = 0;
   int l = 0;
   int n = s.length();
   int Maxlength = 0;
   int arr[26] = {0};
   int lives = 0;

   while(r < n){
      if(arr[s[r] - 'a'] == 0) lives ++;
      arr[s[r]- 'a']++;

      if(lives > k){
         arr[s[l]-'a']--;
         if(arr[s[l]-'a'] == 0) lives--;
         l++;
      }
      
      int len = r-l + 1;
      if(Maxlength < len) Maxlength = len;
      r++;
   }

   return Maxlength;
}
