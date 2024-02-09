/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int maxVal = 0, endIdx = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(1005, 1);
        vector<int> pre(1005, -1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            if(dp[i] > maxVal){
                maxVal = dp[i];
                endIdx = i;
            }
        }
        vector<int> ans;
        while(endIdx != -1){
            ans.push_back(nums[endIdx]);
            endIdx = pre[endIdx];
        }
        return ans;
    }
};
// @lc code=end

