/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dsu;
    vector<int> groups;
    int finds(int type, int n){
        if(dsu[type][n] == n){
            return n;
        }
        return dsu[type][n] = finds(type, dsu[type][n]);
    }

    bool isSame(int type, int a, int b){
        return finds(type, a) == finds(type, b);
    }

    bool unions(int type, int a, int b){
        if(!isSame(type, a, b)){
            dsu[type][finds(type, a)] = finds(type, b);
            groups[type]--;
            return true;
        }
        return false;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = edges.size();
        dsu.assign(3, vector<int>(n + 1));
        groups.assign(3, n);
        for(int i = 0; i <= n; i++){
            dsu[1][i] = dsu[2][i] = i;    
        }
        for(auto it : edges){
            if(it[0] != 3) continue;
            bool ctrl = unions(1, it[1], it[2]);
            if(unions(2, it[1], it[2]) || ctrl){
                ans--;
            }
        }
        for(auto it : edges){
            if(it[0] == 3) continue;
            if(unions(it[0], it[1], it[2])){
                ans--;
            }
        }
        if(groups[1] != 1 || groups[2] != 1){
            ans = -1;
        }
        return ans;
    }
};
// @lc code=end

