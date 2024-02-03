/*
 * @lc app=leetcode id=2527 lang=cpp
 *
 * [2527] Find Xor-Beauty of Array
 */

// @lc code=start
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
// @lc code=end

