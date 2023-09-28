/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution {
public:
    struct pos{
        int num;
        int step;
    }head, tmp;

    struct cmp{
        bool operator()(pos a, pos b){
            return a.step > b.step;
        }
    };

    int snakesAndLadders(vector<vector<int>>& board) {
        int ans = -1;
        int n = board.size();
        int *directTo = (int *)malloc(sizeof(int)*(n*n+1));
        bool *isArrived = (bool *)malloc(sizeof(int)*(n*n+1));
        memset(isArrived, false, sizeof(int)*(n*n+1));
        int direct = 1;
        int cnt = 1;
   
        for(int i=n-1;i>=0;i--){
            if(direct == -1){
                reverse(board[i].begin(), board[i].end());
            }
            for(int j=0;j<n;j++){
                directTo[cnt++] = board[i][j];
            }
            direct *= (-1);
        }
        
        tmp.num = 1;
        tmp.step = 0;
        priority_queue<pos, vector<pos>, cmp> pq;
        pq.push(tmp);
        while(!pq.empty()){
            head = pq.top();
            pq.pop();
            if(head.num == n*n){
                ans = head.step;
                break;
            }
            for(int i=1;i<=6;i++){
                tmp.num = head.num + i;
                tmp.step = head.step + 1;
                if(tmp.num > n*n) continue;
                if(directTo[tmp.num] != -1){
                    tmp.num = directTo[tmp.num];
                }
                if(!isArrived[tmp.num]){
                    pq.push(tmp);
                    isArrived[tmp.num] = true;
                }
                
            }
        }

        return ans;
    }
};
// @lc code=end

