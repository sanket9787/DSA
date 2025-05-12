
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root == nullptr) return ans;
        
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root, 0});
        mp[0] = root->data;
        
        while(!q.empty()){
            auto temp = q.front().first;
            
            int x = q.front().second;
            q.pop();
            
            if(temp -> left){
                mp[x-1] = temp->left->data;
                q.push({temp->left, x-1});
            }
            if(temp -> right){
                mp[x+1] = temp->right->data;
                q.push({temp->right, x+1});
            }
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};