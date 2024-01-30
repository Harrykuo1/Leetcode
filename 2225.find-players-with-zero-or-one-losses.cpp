/*
 * @lc app=leetcode id=2225 lang=cpp
 *
 * [2225] Find Players With Zero or One Losses
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int>mp;
        for(auto it: matches){
            if(!mp.count(it[0])){
                mp[it[0]] = 0;
            }
            mp[it[1]]++;
        }
        vector<int> zero;
        vector<int> one;
        for(auto& [key, value]: mp){
            printf("%d %d\n",key, value);
            if(value == 0){
                zero.push_back(key);
            }
            if(value == 1){
                one.push_back(key);
            }
        }
        return {zero, one};
    }
};
// @lc code=end

