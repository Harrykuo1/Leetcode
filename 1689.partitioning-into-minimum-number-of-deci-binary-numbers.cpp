/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
class Solution {
public:
    int minPartitions(string n) {
        int maxNum = 0;
        for(int i=0;i<n.length();i++){
            maxNum = max(maxNum, n[i]-'0');
        }
        return maxNum;
    }
};
// @lc code=end

