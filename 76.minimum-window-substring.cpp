/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int ansL = 0, ansR = INT_MAX;
        map<char, int> target_map, cnt_map;
        for(auto it : t){
            target_map[it]++;
        }
        int need = target_map.size(), now = 0, l = 0;
        for(int r=0;r<s.size();r++){
            cnt_map[s[r]]++;
            if(cnt_map[s[r]] == target_map[s[r]]){
                now++;
            }
            while(now == need){
                if(r - l < ansR - ansL){
                    ansL = l;
                    ansR = r;
                }
                cnt_map[s[l]]--;
                if(cnt_map[s[l]] < target_map[s[l]]){
                    now--;
                }
                l++;
            }
        }
        if(ansR - ansL == INT_MAX){
            return "";
        }
        return s.substr(ansL, ansR - ansL + 1);

    }
};
// @lc code=end

