/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 5, 0);
        for(int i=0;i<n;i++){
            int subMax = -1;
            for(int j=i;j>=max(i-k+1, 0);j--){
                subMax = max(arr[j], subMax);
                dp[i+1] = max(dp[j] + subMax * (i - j + 1), dp[i+1]);
            }
        }

        return dp[n];
    }
};
// @lc code=end

