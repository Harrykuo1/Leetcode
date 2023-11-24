/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */

// @lc code=start
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            int num = 0;
            for(int j=i;j<=9;j++){
                num = num * 10 + j;
                if(num < low) continue;
                if(num > high) break;
                ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

