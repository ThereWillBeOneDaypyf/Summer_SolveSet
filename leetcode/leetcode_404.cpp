#include<bits/stdc++.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return dfs(root,root);
    }
private:
    int dfs(TreeNode* root,TreeNode* fa);
};

int Solution :: dfs(TreeNode* root,TreeNode* fa)
{
    if(root == nullptr)
        return 0;
    if(root -> left == nullptr && root -> right == nullptr)
    {
        if(fa -> left == root)
            return root -> val;
        else return 0;
    }
    return dfs(root -> left,root) + dfs(root -> right,root);
}