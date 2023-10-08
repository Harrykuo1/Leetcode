/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Solution {
public:
    vector<int>ans;
    int num;

    void dfs(int now, int limit, int k){
        if(now == limit){
            ans.push_back(num);
            return;
        }
        for(int i=0;i<=9;i++){
            if(abs(i-num%10) == k){
                num*=10;
                num+=i;
                dfs(now+1, limit, k);
                num/=10;
            }
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            num = i;
            dfs(1, n, k);
        }
        return ans;
    }
};

// @lc code=end

