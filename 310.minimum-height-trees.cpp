/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> edge[n];
        vector<int> height(n, INT_MAX);
        vector<int> degree(n, 0);
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(degree[i] == 1){
                q.push(i);
                height[i] = 1;
            }
        }
        while(!q.empty()){
            ans.clear();
            int size = q.size();
            for(int i=0;i<size;i++){
                int now = q.front();
                q.pop();
                ans.push_back(now);
                for(int j=0;j<edge[now].size();j++){
                    degree[edge[now][j]]--;
                    if(degree[edge[now][j]] == 1){
                        q.push(edge[now][j]);
                    }
                }
            }
        }
        if(n==1){
            ans.push_back(0);
        }
        return ans;
    }
};
// @lc code=end

