/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */

// @lc code=start
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int posIdx = 0, negIdx = 1;
        for(auto it : nums){
            if(it > 0){
                ans[posIdx] = it;
                posIdx += 2;
            }
            else{
                ans[negIdx] = it;
                negIdx += 2;
            }
        }
        return ans;
    }
};
// @lc code=end

