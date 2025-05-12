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
    //each function call will return - 1 if the absolute difference between the left node and right node of the input node is greater than 1 through this line in code if(abs(lh - rh) > 1) return -1; . if it is not greater than one then it will return the hight of that perticular node given in parameter of the function call through the return statement. 
// so after calling the int lh = gethight() we will check if lh is -1 means the difference between its left and right node is greater than two basically measn if the node is balanced or not. if not -1 then its means its a balanced node then we will be having the value of the hight of that node in lh. 
//similary for rh 
// At the end if both lh and rh are balanced indivisually then we will check difference between lh and rh is greater than 1.

    int gethight(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = gethight(root -> left);

        if(lh == -1) return -1;
        
        int rh = gethight(root -> right);

        if(rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;


        return 1 + max(lh, rh);

    }

    bool isBalanced(TreeNode* root) {
        
        if(gethight(root) == -1) return false;

        return true;

    }
};