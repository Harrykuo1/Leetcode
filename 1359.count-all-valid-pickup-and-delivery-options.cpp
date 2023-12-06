/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
class Solution {
public:
    int countOrders(int n) {
        long long int ans = 1LL;
        for(int i=2;i<=n;i++){
            ans = (ans * (i * 2 - 1) * i) % ((int)1e9 + 7);
        }
        return (int)ans;
    }
};
// @lc code=end

