/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> adj;
    bool visited[105];
    int cnt = 0;

    void dfs(int id){
        for(auto x : adj[id]){
            if(!visited[x]){
                cnt++;
                visited[x] = true;
                dfs(x);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        adj.resize(105);
        int n = bombs.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j) continue;
                long long int x = llabs(bombs[i][0] - bombs[j][0]);
                long long int y = llabs(bombs[i][1] - bombs[j][1]);
                long long int r = bombs[i][2];
                if(x*x+y*y <= r*r){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            memset(visited, false, sizeof(visited));
            visited[i] = true;
            cnt = 1;
            dfs(i);
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end

