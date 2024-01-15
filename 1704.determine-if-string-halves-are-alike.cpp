/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
public:
    bool check(char c){
        char arr[] = "aeiou";
        for(int i=0;i<5;i++){
            if(c == arr[i]){
                return true;
            }
        }
        return false;
    }

    bool halvesAreAlike(string s) {
        int sum1=0, sum2=0;
        int length = s.length();
        for(int i=0;i<length/2;i++){
            if(check(tolower(s[i]))){
                sum1++;
            }
        }
        for(int i=length/2;i<length;i++){
            if(check(tolower(s[i]))){
                sum2++;
            }
        }
        if(sum1 == sum2){
            return true;
        }
        return false;
    }
};
// @lc code=end

