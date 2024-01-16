/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> mp;
        for(string str : dictionary){
            mp[str] = 1;
        }

        int len = s.length();
        vector<int> dp(len+1);
        for(int i=0;i<len;i++){
            dp[i+1] = dp[i] + 1;
            for(int j=0;j<=i;j++){
                string str = s.substr(j, i-j+1);
                if(mp[str] == 1){
                    dp[i+1] = min(dp[j], dp[i+1]);
                }
            }
        }
        return dp[len];
    }
};
// @lc code=end

