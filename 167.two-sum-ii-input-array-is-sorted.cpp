/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int l=0,r=numbers.size()-1;
        while(l<r){
            int tmp=numbers[l]+numbers[r];
            if(tmp==target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            else if(tmp>target){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};
// @lc code=end

