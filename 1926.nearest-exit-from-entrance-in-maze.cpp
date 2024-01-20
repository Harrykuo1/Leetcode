/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
public:
    struct pos{
        int x, y, times;
    };

    bool isNotS(pos now, int sy, int sx){
        if(now.x!=sx || now.y!=sy){
            return true;
        }
        return false;
    }

    bool isEdge(int now ,int limit){
        if(now==0 || now == limit-1){
            return true;
        }
        return false;
    }

    bool isArrived(pos now, int yLimit, int xLimit){
        if((isEdge(now.x, xLimit) || isEdge(now.y, yLimit))){
            return true;
        }
        return false;
    }

    bool isInRange(int y, int x, int yLimit, int xLimit){
        if(0<=y && y<yLimit && 0<=x && x<xLimit){
            return true;
        }
        return false;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int vecX[] = {0, 0, -1, 1};
        int vecY[] = {1, -1, 0, 0};
        int sy = entrance[0];
        int sx = entrance[1];
        int yLimit = maze.size();
        int xLimit = maze[0].size();
        queue<pos>q;
        pos tmp;
        tmp.y = sy;
        tmp.x = sx;
        tmp.times = 0;
        q.push(tmp);
        bool check[1000][1000];
        memset(check, false, sizeof(check));
        check[sy][sx] = true;
        while(!q.empty()){
            pos now = q.front();
            if(isArrived(now, yLimit, xLimit) && isNotS(now, sy, sx)){
                return now.times;
            }
            for(int i=0;i<4;i++){
                if(isInRange(now.y + vecY[i], now.x + vecX[i], yLimit, xLimit) && maze[now.y + vecY[i]][now.x + vecX[i]] == '.' && !check[now.y + vecY[i]][now.x + vecX[i]]){
                    check[now.y + vecY[i]][now.x + vecX[i]] = true;
                    tmp.y = now.y + vecY[i];
                    tmp.x = now.x + vecX[i];
                    tmp.times = now.times + 1;
                    q.push(tmp);
                }
            }
            q.pop();
        }
        return -1;
    }
};
// @lc code=end

