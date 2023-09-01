/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 */

// @lc code=start
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
    int ans = INT_MAX;
    vector<int> vec;

    void takeData(TreeNode* root){
        if(!root) return;
        takeData(root->left);
        vec.push_back(root->val);
        takeData(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        takeData(root);
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i+1] - vec[i] < ans){
                ans = vec[i+1] - vec[i];
            }
        }
        return ans;
    }
};
// @lc code=end

