/*
 * @lc app=leetcode id=2264 lang=cpp
 *
 * [2264] Largest 3-Same-Digit Number in String
 */

// @lc code=start
class Solution {
public:
    string largestGoodInteger(string num) {
        int sel = -1;
        for(int i=0;i<num.length()-2;i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                sel = max((int)(num[i] - '0'), sel);
            }
        }
        string ans = "";
        if(sel != -1){
            for(int i=0;i<3;i++){
                ans += (sel + '0');
            }
        }
        return ans;
    }
};
// @lc code=end

