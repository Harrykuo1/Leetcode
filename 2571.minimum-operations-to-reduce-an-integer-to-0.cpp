/*
 * @lc app=leetcode id=2571 lang=cpp
 *
 * [2571] Minimum Operations to Reduce an Integer to 0
 */

// @lc code=start
class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for(int i=0;i<30;i++){
            if(1<<i & n){
                if(1<<(i+1) & n){
                    n += (1<<i);
                }
                else{
                    n -= (1<<i);
                }
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

