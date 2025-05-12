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
    // void preorderTrav(TreeNode* node, vector<int> &ans){
    //     if(node == nullptr) return;
    //     ans.push_back(node->val);
    //     preorderTrav(node->left, ans);
    //     preorderTrav(node->right, ans);
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        //   vector<int> ans;

        //   preorderTrav(root, ans);
        //   return ans;

        vector<int> ans;
        if(root == nullptr) return ans;
        stack <TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();

            ans.push_back(temp->val);

            if(temp -> right != nullptr) st.push(temp -> right);
            if(temp -> left != nullptr) st.push(temp->left);

        }
        return ans;

    }
};