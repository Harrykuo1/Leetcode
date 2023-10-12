/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int prefix = 0;
        map<int, int>mp;
        mp[0] = 1;
        for(int i=0;i<nums.size();i++){
            prefix += nums[i] % k + k;
            ans += mp[prefix%k];
            mp[(prefix)%k]++;
        }
        return ans;
    }
};
// @lc code=end

