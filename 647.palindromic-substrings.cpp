/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            int l = i, r = i;
            while(0 <= l && r < s.length()){
                if(s[l] != s[r]){
                    break;
                }
                ans++;
                l--;
                r++;
            }
            l = i, r = i + 1;
            while(0 <= l && r < s.length()){
                if(s[l] != s[r]){
                    break;
                }
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};
// @lc code=end

