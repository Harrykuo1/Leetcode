/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    bool isSame(vector<int> a, vector<int> b){
        for(int i=0;i<26;i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        int len1 = s.length();
        int len2 = p.length();
        if(len1 < len2){
            return ans;
        }
        for(int i=0;i<len2;i++){
            cnt1[s[i] - 'a']++;
            cnt2[p[i] - 'a']++;
        }
        if(isSame(cnt1, cnt2)){
            ans.push_back(0);
        }
        for(int i=0;i+len2<len1;i++){
            cnt1[s[i] - 'a']--;
            cnt1[s[i+len2] - 'a']++;
            if(isSame(cnt1, cnt2)){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
// @lc code=end

