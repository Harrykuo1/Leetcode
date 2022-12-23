/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        for(int i=0;i<board.size();i++){
            bool check[10];
            memset(check, false, sizeof(check));
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.') continue;
                if(check[board[i][j] - '0']){
                    ans = false;
                }
                check[board[i][j] - '0'] = true;
            }
        }

        for(int j=0;j<board[0].size();j++){
            bool check[10];
            memset(check, false, sizeof(check));
            for(int i=0;i<board.size();i++){
                if(board[i][j] == '.') continue;
                if(check[board[i][j] - '0']){
                    ans = false;
                }
                check[board[i][j] - '0'] = true;
            }
        }

        for(int i=0;i<board.size();i+=3){
            for(int j=0;j<board[0].size();j+=3){
                bool check[10];
                memset(check, false, sizeof(check));
                for(int a=0;a<3;a++){
                    for(int b=0;b<3;b++){
                        if(board[i+a][j+b] == '.') continue;
                        if(check[board[i+a][j+b] - '0']){
                            ans = false;
                        }
                        check[board[i+a][j+b] - '0'] = true;
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end

