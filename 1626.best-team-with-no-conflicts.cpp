/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> arr(scores.size());
        for(int i=0;i<scores.size();i++){
            arr[i] = {scores[i], ages[i]};
        }
        sort(arr.begin(), arr.end(), cmp);
        for(int i=0;i<scores.size();i++){
            printf("%d %d\n",arr[i][0], arr[i][1]);
        }

        int ans = 0;
        int* dp = (int*)malloc(sizeof(int) * scores.size());
        for(int i=0;i<scores.size();i++){
            dp[i] = arr[i][0];
            for(int j=0;j<i;j++){
                if(arr[j][0] <= arr[i][0]){
                    dp[i] = max(dp[i], dp[j] + arr[i][0]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
// @lc code=end

