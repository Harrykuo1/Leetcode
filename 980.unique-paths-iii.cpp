/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> mp;
    int ans = 0;
    int vecX[4] = {0, 0, -1, 1};
    int vecY[4] = {1, -1, 0, 0};
    int limit=0;
    bool check[300][300];

    void dfs(int y, int x, int now){
        if(now == limit && mp[y][x] == 2){
            ans++;
            return;
        }
        if(now == limit || mp[y][x] == 2){
            return;
        }

        for(int i=0;i<4;i++){
            int nowY = y + vecY[i];
            int nowX = x + vecX[i];
            if(0<=nowY && nowY<mp.size() && 0<=nowX && nowX<mp[0].size() && (mp[nowY][nowX]==0 || mp[nowY][nowX]==2) && check[nowY][nowX]){
                check[nowY][nowX] = false;
                dfs(nowY, nowX, now+1);
                check[nowY][nowX] = true;
            }
        }
        return;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        memset(check, true, sizeof(check));
        mp = grid;
        int sY, sX;
        for(int i=0;i<mp.size();i++){
            for(int j=0;j<mp[0].size();j++){
                if(mp[i][j] == 1){
                    sY = i;
                    sX = j;
                    limit++;
                    check[i][j] = false;
                }
                if(mp[i][j] == 0){
                    limit++;
                }
            }
        }
        dfs(sY, sX, 0);
        return ans;
    }
};
// @lc code=end

