/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
public:
    struct node{
        int node;
        int weight;
        int step;
    }head, tmp;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<node>> edges;
        edges.resize(n);
        for(int j=0;j<flights.size();j++){
            tmp.node = flights[j][1];
            tmp.weight = flights[j][2];
            edges[flights[j][0]].push_back(tmp);
        }
        int ans = 2147483647;
        queue<node> pq;
        tmp.node = src;
        tmp.weight = 0;
        tmp.step = -1;
        pq.push(tmp);
        vector<int> dis(n, 2147483647);
        dis[src] = 0;
        while(!pq.empty()){
            head = pq.front();
            pq.pop();
            if(head.step>k) continue;
            if(head.node == dst){
                ans = min(ans, head.weight);
                continue;
            }
            if(dis[head.node] < head.weight) continue;
            dis[head.node] = head.weight;
            for(int i=0;i<edges[head.node].size();i++){
                tmp.node = edges[head.node][i].node;
                tmp.weight = head.weight + edges[head.node][i].weight;
                tmp.step = head.step + 1;
                pq.push(tmp);
            }
        }
        if(ans == 2147483647){
            return -1;
        }
        return ans;
    }
};
// @lc code=end

