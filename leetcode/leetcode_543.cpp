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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        dfs(root);
        return max_d;
    }
private: 
    int max_d = 0;
    int dfs(TreeNode* r);
};
int Solution :: dfs(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    int l = dfs(root -> left);
    int r = dfs(root -> right);
    max_d = std::max(max_d,l + r);
    return std::max(l,r) + 1;
}