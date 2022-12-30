/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(10005, 10005);
        dp[0] = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<=nums[i] && i+j<nums.size();j++){
                dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
        return dp[nums.size()-1];
    }
};



// @lc code=end

