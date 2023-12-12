/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
    int ans = 0;
    int cntArr[10];
    void dfs(TreeNode* now){
        cntArr[now->val]++;
        if(!now->left && !now->right){
            int odd = 0;
            for(int i=0;i<=9;i++){
                if(cntArr[i] % 2){
                    odd++;
                }
            }
            if(odd <= 1){
                ans++;
            }
            cntArr[now->val]--;
            return;
        }
        if(now->left){
            dfs(now->left);
        }
        if(now->right){
            dfs(now->right);
        }
        cntArr[now->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

