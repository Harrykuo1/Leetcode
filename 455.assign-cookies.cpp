/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ret = 0;
        for(int i=0;i<s.size() && ret < g.size();i++){
            if(g[ret] <= s[i]){
                ret++;
            }
        }
        return ret;
    }
};
// @lc code=end

