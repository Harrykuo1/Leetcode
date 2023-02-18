/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>(1, 1));
        for(int i=0;i<numRows-1;i++){
            for(int j=0;j<i;j++){
                ans[i+1].push_back(ans[i][j] + ans[i][j+1]);
            }
            ans[i+1].push_back(1);
        }
        return ans;
    }
};
// @lc code=end

