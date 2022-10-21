/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    long long int num;
    bool isPalindrome(int x) {
        num=0;
        reverse(x);
        if(x<0 || x>2147483647 || x<-2147483648 || x!=num){
            return false;
        }
        return true;
    }
    void reverse(int y){
        while(y){
            num*=10;
            num+=y%10;
            y/=10;
        }
    }
};
// @lc code=end

