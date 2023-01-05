/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;

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
            vector<string> tmpVec;
            for(int i=0;i<n;i++){
                string tmpStr = "";
                for(int j=0;j<n;j++){
                    if(cols[i] == j){
                        tmpStr+='Q';
                    }
                    else{
                        tmpStr+='.';
                    }
                }
                tmpVec.push_back(tmpStr);
            }
            ans.push_back(tmpVec);
        }
        for(int i=0;i<n;i++){
            if(check(now, i)){
                colCheck[i] = false;
                cols[now] = i;
                dfs(now+1, n);
                colCheck[i] = true;
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        memset(colCheck, true, sizeof(colCheck));
        dfs(0, n);
        return ans;
    }
};
// @lc code=end

