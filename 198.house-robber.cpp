/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()>1){
            nums[1] = max(nums[0], nums[1]);
        }
        for(int i=2;i<nums.size();i++){
            nums[i] = max(nums[i-2]+nums[i], nums[i-1]);
        }
        return nums[(nums.size()-1)];
    }
};
// @lc code=end

