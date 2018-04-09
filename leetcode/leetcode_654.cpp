#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums);
private:
    TreeNode* find_tree_node(int l,int r,vector<int>& nums,vector<bool>& vis);
};

TreeNode* Solution :: constructMaximumBinaryTree(vector<int>& nums)
{
    TreeNode* root;
    vector<bool> vis;   
    vis.resize(nums.size(),false);
    int sz = nums.size();
    return find_tree_node(0,sz - 1,nums,vis);
}

TreeNode* Solution :: find_tree_node(int l,int r,vector<int>& nums,vector<bool>& vis)
{
    if(l > r)
        return nullptr;
    int pos = -1;
    for(int i = l;i <= r;i ++)
    {
        if(vis[i])
            continue;
        if(pos == -1 || nums[i] >= nums[pos])
            pos = i;
    }
    if(pos == -1)
        return  nullptr;
    TreeNode* root = new TreeNode(nums[pos]);
    vis[pos] = 1;
    root -> left = find_tree_node(l,pos - 1,nums,vis);
    root -> right = find_tree_node(pos + 1,r,nums,vis);
    return root;
}
