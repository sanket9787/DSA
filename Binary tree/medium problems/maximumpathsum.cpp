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
    int getmax(TreeNode* node, int &maxi){
        if(node == nullptr) return 0;

        // if the lh and rh is lesser than zero then take 0 as maximum for lh and rh
        int lh = max(0, getmax(node->left, maxi));
        int rh = max(0, getmax(node->right, maxi));
        
        //store the maximum path sum 
        maxi = max(maxi, node->val + lh + rh);

        //each function call will return the node->data + maximum value between its right or left node
        return node->val + max(lh, rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        getmax(root, maxi);

        return maxi;
    }
};