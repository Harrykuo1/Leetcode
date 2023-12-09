/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
class Solution {
public:
    int dfs(int n, vector<vector<int>> &edges, vector<int> &informTime){
        int maxTime = 0;
        for(auto x : edges[n]){
            maxTime = max(maxTime, informTime[n] + dfs(x, edges, informTime));
        }
        return maxTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> edges(n+5, vector<int>());
        for(int i=0;i<n;i++){
            if(manager[i] == -1) continue;
            edges[manager[i]].push_back(i);
        }
        int ans = dfs(headID, edges, informTime);
        return ans;
    }
};
// @lc code=end

