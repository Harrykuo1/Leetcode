/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        vector<int> cntS(26, 0);
        bool sOver2 = false;
        for(int i=0;i<s.length();i++){
            cntS[s[i]-'a']++;
            if(cntS[s[i]-'a'] >= 2) sOver2 = true;
        }
        if(s == goal){
            return sOver2;
        }
        if(s.length() != goal.length()){
            return false;
        }
        int l = 0, r = s.length()-1;
        while(l<s.length() && s[l]==goal[l]){
            l++;
        }
        while(r>=0 && s[r]==goal[r]){
            r--;
        }
        swap(s[l], s[r]);
        return s == goal;

    }
};

// @lc code=end

