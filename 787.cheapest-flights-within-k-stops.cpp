/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n + 1, INT_MAX);
        vector<pair<int, int>> graph[n + 1];
        for(auto &it : flights){
            graph[it[0]].push_back({it[1], it[2]});
        }

        dist[src] = 0;
        int step = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        while(!q.empty() && step <= k){
            int size = q.size();
            while(size--){
                int now = q.front().first;
                int nowDist = q.front().second;
                for(auto it : graph[now]){
                    int nxt = it.first;
                    int nxtDist = it.second + nowDist;
                    if(nxtDist < dist[nxt]){
                        dist[nxt] = nxtDist;
                        q.push({nxt, nxtDist});
                    }
                }
                q.pop();
            }
            step++;
        }
        if(dist[dst] == INT_MAX) dist[dst] = -1;
        return dist[dst];
    }
};
// @lc code=end

