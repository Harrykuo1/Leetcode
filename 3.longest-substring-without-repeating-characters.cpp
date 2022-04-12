/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>maps;
        int left=-1;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(maps.count(s[i])!=0 && maps[s[i]]>left){
                left=maps[s[i]];
            }
            maps[s[i]]=i;
            ans=max(ans,i-left);
        }
        return ans;
    }
};
// @lc code=end

