/*
 * @lc app=leetcode id=2485 lang=cpp
 *
 * [2485] Find the Pivot Integer
 */

// @lc code=start
class Solution {
public:
    int pivotInteger(int n) {
        int ans = -1, l = 0, r = (n + 1) * n / 2;
        for(int i=1;i<=n;i++){
            l += i;
            if(l == r){
                ans = i;
                break;
            }
            r -= i;
        }
        return ans;
    }
};
// @lc code=end

