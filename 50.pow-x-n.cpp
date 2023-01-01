/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, long long int n) {
        if(x==1){
            return 1;
        }
        if(n==0){
            return 1;
        }
        if(x==0){
            return 0;
        }
        if(n<0){
            return myPow(1/x, n*(-1));
        }
        else if(n%2==0){
            return myPow(x*x, n/2);
        }
        else{
            return x*myPow(x*x, n/2);
        }
    }
};
// @lc code=end

