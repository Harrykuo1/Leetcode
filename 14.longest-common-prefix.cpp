/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int j=0;j<strs[0].size();j++){
            char base = strs[0][j];
            for(int i=0;i<strs.size();i++){
                if(j >= strs[i].size() || strs[i][j] != base){
                    return ans;
                }
            }
            ans += base;
        }
        return ans;
    }
};
// @lc code=end

