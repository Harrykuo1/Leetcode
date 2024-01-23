/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution {
public:
    int *dsu;
    void initDsu(int n){
        for(int i=0;i<n;i++){
            dsu[i] = i;
        }
        return;
    }

    int findDsu(int num){
        if(dsu[num] == num){
            return num;
        }
        return dsu[num] = findDsu(dsu[num]);
    }

    bool isSame(int a, int b){
        return findDsu(a) == findDsu(b);
    }

    void unionDsu(int a, int b){
        dsu[findDsu(a)] = findDsu(b);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        dsu = (int*)malloc(sizeof(int)*n);
        initDsu(n);
        for(int i=0;i<edges.size();i++){
            unionDsu(edges[i][0], edges[i][1]);
        }
        return isSame(source, destination);
    }
};
// @lc code=end

