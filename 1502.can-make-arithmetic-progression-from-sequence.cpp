/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 */

// @lc code=start
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int maxNum = INT_MIN, minNum = INT_MAX, d;
        unordered_map<int, int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]] = 1;
            maxNum = max(maxNum, arr[i]);
            minNum = min(minNum, arr[i]);
        }
        d = (maxNum - minNum) / (arr.size() - 1);
        if(minNum + d * (arr.size() - 1) != maxNum) return false;
        for(int i = 0; i < arr.size(); i++){
            if(mp[minNum + d * i] == 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

