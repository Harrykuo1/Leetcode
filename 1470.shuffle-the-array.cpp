/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        for(int i=0;i<n;i++){
            ans[2*i] = nums[i];
            ans[2*i+1] = nums[n+i];
        }
        return ans;
    }
};
// @lc code=end

