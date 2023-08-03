/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    set<vector<int>> s;

    void dfs(int now, int limit, vector<int>& nums){
        if(tmp.size()>=2 && !s.count(tmp)){
            ans.push_back(tmp);
            s.insert(tmp);
        }
        if(now == limit){
            return;
        }
        for(int i=now;i<limit;i++){
            if(tmp.size()>=1 && nums[i]<tmp[tmp.size()-1]) continue;
            tmp.push_back(nums[i]);
            dfs(i+1, limit, nums);
            tmp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, nums.size(), nums);
        return ans;
    }
};
// @lc code=end

