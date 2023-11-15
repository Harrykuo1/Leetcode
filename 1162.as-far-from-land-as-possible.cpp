/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int y, x, newX, newY, ans = 0, n = grid.size();
        int direct[][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                   q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                y = q.front().first;
                x = q.front().second;
                for(int j=0;j<4;j++){
                    newY = y + direct[j][0];
                    newX = x + direct[j][1];
                    if(0<=newY && newY<n && 0<=newX && newX<n && grid[newY][newX] == 0){
                        grid[newY][newX] = grid[y][x]+1;
                        q.push({newY, newX});
                        ans = max(ans, grid[newY][newX]);
                    }
                }q.pop();
            }
        }
        return ans!=0 ? ans-1 : -1;
    }
};
// @lc code=end

