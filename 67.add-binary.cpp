/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length()) swap(a, b);
        int plus = 0, aIndex = a.length() - 1, bIndex = b.length() - 1;
        while(aIndex >= 0){
            a[aIndex] += plus;
            plus = 0;
            if(bIndex >= 0) a[aIndex] += b[bIndex] - '0';
            if(a[aIndex] >= '2'){
                a[aIndex] -= 2;
                plus = 1;
            }
            aIndex--;
            bIndex--;
        }
        if(plus){
            a = '1' + a;
        }
        return a;
    }
};
// @lc code=end

