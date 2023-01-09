/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    int ans=0;

    int cols[12];
    bool colCheck[12];

    bool check(int row, int col){
        if(!colCheck[col]){
            return false;
        }
        for(int i=0;i<row;i++){
            if(cols[i] == col){
                return false;
            }
            if(abs(i-row) == abs(cols[i]-col)){
                return false;
            }
        }
        return true;
    }

    void dfs(int now, int n){
        if(now == n){
            ans++;
        }
        for(int i=0;i<n;i++){printf("00\n");
            if(check(now, i)){
                colCheck[i] = false;
                cols[now] = i;
                dfs(now+1, n);
                colCheck[i] = true;
            }
        }
    }

    int totalNQueens(int n) {
        memset(colCheck, true, sizeof(colCheck));
        dfs(0, n);
        return ans;
    }
};
// @lc code=end

