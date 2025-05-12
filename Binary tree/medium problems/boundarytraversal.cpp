https://www.naukri.com/code360/problems/boundary-traversal-of-binary-tree_790725?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION


/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> *node){
    if(node -> left == nullptr && node -> right == nullptr) return true;
    return false;
}

void traverseLeft(TreeNode<int> *node, vector<int> &ans){

    if(node == nullptr) return;
    if(isLeaf(node)) return;
    
    ans.push_back(node -> data);

    if(node -> left) {
        traverseLeft(node->left,ans);
    }else if(node -> right){
        traverseLeft(node->right,ans);
    }
}

void traverseRight(TreeNode<int> *node, vector<int> &ans){
    if(node == nullptr) return;
    if(isLeaf(node)) return;

    if(node -> right) {
        traverseRight(node->right,ans);
    }else if(node -> left){
        traverseRight(node->left,ans);
    }

    ans.push_back(node -> data);

}

void traverseBottom(TreeNode<int> *node, vector<int> &ans){
    if(node == nullptr) return;
    if(isLeaf(node)) ans.push_back(node -> data);
    traverseBottom(node->left,ans);
    traverseBottom(node->right,ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int>ans;
    ans.push_back(root -> data);
    if(isLeaf(root)) return ans;

    traverseLeft(root->left, ans);
    traverseBottom(root, ans);
    traverseRight(root->right, ans);  

    return ans;
}
