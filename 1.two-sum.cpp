/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> maps;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int tmp=target-nums[i];
            auto it=maps.find(tmp);
            if(it!=maps.end()){
                ans.push_back(i);
                ans.push_back(it->second);
                break;
            }
            maps.insert(pair<int,int>(nums[i],i));
            
        }
        return ans;
    }
};
// @lc code=end

