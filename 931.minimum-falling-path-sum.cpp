/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int limit;
    bool checkRange(int num){
        if(0<=num && num<limit){
            return true;
        }
        return false;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        limit = matrix[0].size();
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int minNum = 99999;
                for(int k=-1;k<=1;k++){
                    if(checkRange(j+k) && minNum>matrix[i-1][j+k]){
                        minNum = matrix[i-1][j+k];
                    }
                }
                matrix[i][j] += minNum; 
            }
        }
        int ans = 9999999;
        for(int j=0;j<matrix[0].size();j++){
            //printf("%d ",matrix[matrix.size()-1][j]);
            if(ans>matrix[matrix.size()-1][j]){
                ans = matrix[matrix.size()-1][j];
            }
        }
        return ans;
    }
};
// @lc code=end

