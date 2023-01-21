/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long long int l=0, r=x, mid, ans;
        while(l<=r){
            mid = l+(r-l)/2;
            if(mid*mid==x){
                ans = mid;
                break;
            }
            else if(mid*mid<x){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return (int)ans;
    }
};
// @lc code=end

