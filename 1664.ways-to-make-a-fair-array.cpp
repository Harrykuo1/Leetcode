/*
 * @lc app=leetcode id=1664 lang=cpp
 *
 * [1664] Ways to Make a Fair Array
 */

// @lc code=start
class Solution {
public:
    bool check(int num, int limit){
        if(0<=num && num<limit){
            return true;
        }
        return false;
    }

    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        
        for(int i=0;i<n;i++){
            dp[0][i] = i-2>=0 ? dp[0][i-2] + nums[i] : nums[i] ;
        }
        for(int i=n-1;i>=0;i--){
            dp[1][i] = i+2<n ? dp[1][i+2] + nums[i] : nums[i] ;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int sum1 = 0, sum2 = 0;
            if(check(i-2, n)){
                sum1 += dp[0][i-2];
            }
            if(check(i+1, n)){
                sum1 += dp[1][i+1];
            }
            if(check(i-1, n)){
                sum2 += dp[0][i-1];
            }
            if(check(i+2, n)){
                sum2 += dp[1][i+2];
            }
            if(sum1 == sum2){
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

