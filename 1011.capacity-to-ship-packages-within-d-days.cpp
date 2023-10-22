/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& weights,int day,int maxW){
        int tmp = 0;
        int now = 0;
        for(int i=0;i<weights.size();i++){
            if(tmp + weights[i] > maxW){
                tmp = 0;
                now++;
            }
            tmp += weights[i];
        }
        if(now >= day){
            return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = weights[0], r = 0, mid;
        for(int i=0;i<weights.size();i++){
            l = max(l, weights[i]);
            r += weights[i];
        }
        while(l<r){
            mid = l + (r - l) / 2;
            if(check(weights, days, mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};

// @lc code=end

