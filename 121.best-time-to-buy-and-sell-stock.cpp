/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, low = prices[0];
        for(int i=1;i<prices.size();i++){
            ans = max(ans, prices[i]-low);
            low = min(low, prices[i]);
        }
        return ans;
    }
};
// @lc code=end

