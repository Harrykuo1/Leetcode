/*
 * @lc app=leetcode id=1513 lang=cpp
 *
 * [1513] Number of Substrings With Only 1s
 */

// @lc code=start
class Solution {
public:
    int numSub(string s) {
        long long ans = 0LL;
        long long tmp = 0LL;
        int sLen = s.length();
        for(int i=0;i<sLen;i++){
            if(s[i] == '0'){
                ans += (tmp*(tmp+1)/2) % 1000000007;
                ans %= 1000000007;
                tmp = 0;
            }
            else{
                tmp++;
            }
        }
        ans += tmp*(tmp+1)/2;
        return (int)(ans % 1000000007);
    }
};

// @lc code=end

