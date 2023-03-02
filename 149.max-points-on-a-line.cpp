/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:
    int cross(int x1, int y1, int x2, int y2){
        return x1*y2 - x2*y1;
    }

    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1){
            return 1;
        }
        int ans = 2;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int cnt = 2;
                for(int k=0;k<points.size();k++){
                    if(k==i || k==j){
                        continue;
                    }
                    if(cross(points[i][0]-points[j][0], points[i][1]-points[j][1], points[i][0]-points[k][0], points[i][1]-points[k][1])==0){
                        cnt++;
                    }
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
// @lc code=end

