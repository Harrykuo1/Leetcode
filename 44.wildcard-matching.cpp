/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[2005][2005];
        memset(dp, false, sizeof(dp));
        int pLen = p.length();
        int sLen = s.length();
        dp[0][0] = true;
        for(int i=1;i<=pLen;i++){
            if(p[i-1] == '*'){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int i=1;i<=pLen;i++){
            for(int j=1;j<=sLen;j++){
                if((p[i-1] == s[j-1] || p[i-1]=='?') && dp[i-1][j-1]){
                    dp[i][j] = true;
                }
                else if(p[i-1] == '*' && (dp[i][j-1] || dp[i-1][j])){
                     dp[i][j] = true;
                }
            }
        }
        return dp[pLen][sLen];
    }
};
// @lc code=end

