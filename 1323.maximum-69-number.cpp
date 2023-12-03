/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
public:
    int maximum69Number (int num) {
        stringstream stream;
        stream<<num;
        string s;
        stream>>s;
        int length = s.length();
        for(int i=0;i<length;i++){
            if(s[i] == '6'){
                s[i] = '9';
                break;
            }
        }
        stringstream streams;
        streams<<s;
        streams>>num;
        return num;
    }
};
// @lc code=end

