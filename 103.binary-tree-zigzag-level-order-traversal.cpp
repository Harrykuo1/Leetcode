/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        TreeNode* now;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> tmp_vec;
            for(int i=0;i<size;i++){
                now = q.front();
                q.pop();
                if(!now) continue;
                tmp_vec.push_back(now->val);
                q.push(now->left);
                q.push(now->right);
            }
            if(ans.size()%2){
                reverse(tmp_vec.begin(), tmp_vec.end());
            }
            if(tmp_vec.size()){
                ans.push_back(tmp_vec);
            }
        }
        return ans;
    }
};
// @lc code=end

