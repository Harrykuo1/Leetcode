/*
 * @lc app=leetcode id=2306 lang=cpp
 *
 * [2306] Naming a Company
 */

// @lc code=start
class Solution {
public:
    #define x first
    #define y second
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0LL, same;
        unordered_map<string, int> mp[26];
        vector<int> cnt(26, 0);
        for(int i=0;i<ideas.size();i++){
            mp[ideas[i][0] - 'a'][ideas[i].substr(1)] = 1;
            cnt[ideas[i][0] - 'a']++;
        }
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                long long same = 0LL;
                for (auto it=mp[i].begin();it!=mp[i].end();it++){
                    if(mp[j].find(it->first)!=mp[j].end()){
                        same++;
                    }
                }
                ans += (cnt[i]-same) * (cnt[j]-same) * 2;
            }
        }
        return ans;
    }
};
// @lc code=end

