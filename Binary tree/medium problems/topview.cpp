/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

Problem link : 

https://www.naukri.com/code360/problems/top-view-of-binary-tree_799401?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

************************************************************/
#include <bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if(root == nullptr) return ans;

    //store the node and {x, y}  value in the q : for this question actually dont need y value
    queue<pair<TreeNode<int>*, pair<int,int>>> q;

    //to store column value and first node of colums data. {x, data}
    map<int,int>mp;

    //pushing root and x = 0, y = 0 in q
    q.push({root, {0,0}});

    // push first columns value as x = 0; in map
    mp[0] = root->data;

    while(!q.empty()){
        //define a temporary node variable to pop it out later
        TreeNode<int>* temp = q.front().first;

        //columns value will be q's front's second and its first.
        int x = q.front().second.first;
        int y = q.front().second.second;

        q.pop();

        //if temp->left exists
        if(temp->left){
            // check if colums value is already there in map if not 
            //then push the value of column - 1 that is x - 1 into the map
            if(mp.find(x-1) == mp.end()) mp[x-1] = temp->left->data;

            //after pushing into map update the q by pushing the left node and its x and y values.
            q.push({temp->left,{x-1,y+1}});
        }
        if(temp->right){
            //similarly check for right node
            if(mp.find(x+1) == mp.end()) mp[x+1] = temp->right->data;
            q.push({temp->right,{x+1,y+1}});
        }
    }

    //push the data column wise
    for(auto it : mp){
        ans.push_back(it.second);
    }

    return ans;
}
