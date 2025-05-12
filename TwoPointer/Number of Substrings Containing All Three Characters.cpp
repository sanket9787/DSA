class Solution {
public:
    //This is less optimal as we are using map we can use vector also to store the elements a,b,c count.

    //Here we are using the map becuase there can me duplicate a,b,c so while doing the l++ we need to check if it is the same elemnent if it is the same from left then dont erase the element from map just reduce the count of that element. when the map[s[l]] becomes zero then only reduce the map size.

    int func1(string s, int k){
        int l = 0;
        int r = 0;
        int n = s.length();
        int anscount = 0;
        unordered_map<char, int> map;

        while(r < n){
            map[s[r]]++;
            while(map.size()> k){
                map[s[l]]--;
                if(map[s[l]] == 0) map.erase(s[l]);
                l++;
            }
            anscount = anscount + r - l + 1;
            r++;
        }
        cout << anscount<<" ";
        return anscount;
    }
    int numberOfSubstrings(string s) {

        //find : number of subarrays containing lesser than equal to 3 characters - number of subarrays containing lesser than equal to 2 characters.

        return func1(s, 3) - func1(s, 2);
    }
};