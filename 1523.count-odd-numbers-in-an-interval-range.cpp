/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start
class Solution {
public:
    int countOdds(int low, int high) {
        low = low%2 ? low: low+1;
        high = high%2 ? high: high-1;
        return (high - low)/2+1;
    }
};
// @lc code=end

