/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
    int ansDeep = 0;
    int *sumArr;

    void dfs(TreeNode* now, int deepNow){
        sumArr[deepNow] += now->val;
        if(deepNow > ansDeep){
            ansDeep = deepNow;
        }
        if(now->left!=NULL){
            dfs(now->left, deepNow+1);
        }
        if(now->right!=NULL){
            dfs(now->right, deepNow+1);
        }
    }

    int deepestLeavesSum(TreeNode* root) {
        sumArr = (int*)malloc(10000*sizeof(int));
        for(int i=0;i<10000;i++){
            sumArr[i]=0;
        }
        dfs(root, 0);
        return sumArr[ansDeep];
    }
};
// @lc code=end

