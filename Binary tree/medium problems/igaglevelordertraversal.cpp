/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);

        //flag to check if its from left to right Or right to left
        bool flag = true;

        //two loops while loop is to store the nodes in queue at each level during each iteration
        //eg. for first iteration level 0 node will be store in queue.at second iteration queue will store two elements.
        // seocnd for is to traverse ech node in the queue according to the size of queue.
        while(!q.empty()){

            //get the size of queue
            int size = q.size();
            vector<int> temp;

            //traverse for each node in the queue level wise size
            for(int i = 0 ;i < size; i++){
                if(q.empty()) break;
                TreeNode* node = q.front();
                temp.push_back(node ->val);
                q.pop();

                if(node -> left != nullptr) q.push(node ->left);
                if(node ->right != nullptr) q.push(node ->right);
            }
           
           // to insert from left to right
            if(flag == true){
                ans.push_back(temp);
                flag = false;
            }else{
                // to insert from right to left
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                flag = true;
            }    
           
        }

        return ans;
    }

};