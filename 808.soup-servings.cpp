/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
class Solution {
public:
    vector<vector<double>> dp;

    double dfs(int a, int b){
        if(a <= 0 && b <= 0){
            return 0.5;
        }
        else if(a <= 0){
            return 1.0;
        }
        else if(b <= 0){
            return 0.0;
        }
        else if(dp[a][b]){
            return dp[a][b];
        }
        return dp[a][b] = 0.25 * (dfs(a-100, b) + dfs(a-75, b-25) + dfs(a-50, b-50) + dfs(a-25, b-75));
    }

    double soupServings(int n) {
        if(n > 3275){
            return 1.0;
        }
        dp.assign(n+1, vector<double>(n+1, 0.0));
        return dfs(n, n);
    }
};
// @lc code=end

