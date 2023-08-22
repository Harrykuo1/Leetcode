/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool isSame(vector<int> cnt1, vector<int> cnt2){
        for(int i=0;i<26;i++){
            if(cnt1[i] != cnt2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt1(27, 0);
        vector<int> cnt2(27, 0);
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2){
            return false;
        }
        for(int i=0;i<len1;i++){
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        if(isSame(cnt1, cnt2)){
            return true;
        }
        for(int i=0;i+len1<len2;i++){
            cnt2[s2[i] - 'a']--;
            cnt2[s2[i+len1] - 'a']++;
            if(isSame(cnt1, cnt2)){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

