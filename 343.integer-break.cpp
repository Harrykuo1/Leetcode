/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
public:
    int power(int base, int pows){
        int ret = 1;
        for(int i=1;i<=pows;i++){
            ret *= base;
        }
        return ret;
    }

    int integerBreak(int n) {
        int ans = 0;
        for(int i=2;i<=n;i++){
            int num = n / i;
            int remain = n % i;
            int tmp = power(num + 1, remain) * power(num, i - remain);
            ans = max(tmp, ans);
        }
        return ans;
    }
};
// @lc code=end

