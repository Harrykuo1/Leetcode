/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
public:
    bool inRange(int y, int x, int n){
        if(0<=y && y<n && 0<=x && x<n){
            return true;
        }
        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dirs{ {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
        int n = grid.size();
        int dis[n+5][n+5];
        memset(dis, 0x3f, sizeof(dis));
        dis[0][0] = 1;
        queue<pair<int, int>> q;
        int ans = -1;
        if(grid[0][0] != 1){
            q.push({0,0});
        }
        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            if(y == n-1 && x == n-1){
                ans = dis[y][x];
                break;
            }
            q.pop();
            for(auto dir:dirs){
                int newY = y + dir[0];
                int newX = x + dir[1];
                if(inRange(newY, newX, n) && grid[newY][newX] == 0){
                    if(dis[newY][newX] > dis[y][x] + 1){
                        dis[newY][newX] = dis[y][x] + 1;
                        q.push({newY, newX});
                    }
                }
            }
        }
        return ans;
    }
};

// @lc code=end

