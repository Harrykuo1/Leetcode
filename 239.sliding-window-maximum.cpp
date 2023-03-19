/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> s;
        for(int i=0;i<k-1;i++){
            s.insert(nums[i]);
        }
        for(int i=k-1;i<nums.size();i++){
            s.insert(nums[i]);
            ans.push_back(*s.rbegin());
            auto it = s.lower_bound(nums[i-k+1]);
            s.erase(it);
        }
        return ans;
    }
};
// @lc code=end

