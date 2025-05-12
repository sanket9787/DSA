int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int>map;
        int l = 0;
        int r = 0;
        int n = arr.size();
        int maxi = 0;
        
        while(r < n){
            
            map[arr[r]]++;
            
            if(map.size()>2){
                map[arr[l]]--;
                if(map[arr[l]] == 0) map.erase(arr[l]);
                l++;
            }
            
            maxi = max(maxi, r - l+1);
            r++;
        }
        
        return maxi;
    }