/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[2][1005];
        int len1 = text1.length();
        int len2 = text2.length();
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
                if(text1[i-1] == text2[j-1]){
                    dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j-1]+1);
                }
            }
        }
        return dp[len1%2][len2];
    }
};
// @lc code=end

