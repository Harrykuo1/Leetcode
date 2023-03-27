/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    vector<int>vec;
    int dp[10005];

    void init(){
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=100;i++){
            vec.push_back(i*i);
        }
    }

    int numSquares(int n) {
        init();
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            for(int j=0;j<100;j++){
                if(i-vec[j] >= 0){
                    dp[i] = min(dp[i], dp[i - vec[j]]+1);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

