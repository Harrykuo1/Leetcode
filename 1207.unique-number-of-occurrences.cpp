/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bool ans = true;
        map<int, int> mp;
        for(auto it: arr){
            mp[it]++;
        }

        set<int>st;
        for(auto [key, value]: mp){
            if(!st.count(value)){
                st.insert(value);
            }
            else{
                ans = false;
            }
        }
        return ans;
    }
};
// @lc code=end

