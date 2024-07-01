/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i = 2; i < arr.size(); i++){
            if(arr[i] % 2 && arr[i - 1] % 2 && arr[i - 2] % 2){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

