/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> dis(2, vector<int>(n, INT_MAX));
        vector<int> redTo[n];
        vector<int> blueTo[n];
        vector<int> ans(n, INT_MAX);
        for(int i=0;i<redEdges.size();i++){
            redTo[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for(int i=0;i<blueEdges.size();i++){
            blueTo[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        dis[0][0] = 0;
        dis[1][0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            if(dis[0][now] != INT_MAX){
                for(int i=0;i<blueTo[now].size();i++){
                    int to = blueTo[now][i];
                    if(dis[1][to] > dis[0][now] + 1){
                        q.push(to);
                        dis[1][to] = dis[0][now] + 1;
                    }
                }
            }
            if(dis[1][now] != INT_MAX){
                for(int i=0;i<redTo[now].size();i++){
                    int to = redTo[now][i];
                    if(dis[0][to] > dis[1][now] + 1){
                        q.push(to);
                        dis[0][to] = dis[1][now] + 1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            ans[i] = min(dis[0][i], dis[1][i]);
            if(ans[i] == INT_MAX) ans[i] = -1;
        }
        return ans;
    }
};
// @lc code=end

