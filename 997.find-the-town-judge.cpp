/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> table;
        int* trustTo = (int*)malloc(sizeof(int) * (n+1));
        table.resize(n+1);
        memset(trustTo, 0, sizeof(int)*(n+1));
        for(auto &v:trust){
            table[v[1]].push_back(v[0]);
            trustTo[v[0]]++;
        }
        int cnt = 0;
        int ans = -1;
        for(int i=1;i<=n;i++){
            if(table[i].size() == n-1){
                cnt++;
                ans = i;
            }
        }
        if(cnt == 1 && trustTo[ans]==0){
            return ans;
        }
        else{
            return -1;
        }
    }
};

// @lc code=end

