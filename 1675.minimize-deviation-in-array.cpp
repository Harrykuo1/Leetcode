/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */

// @lc code=start
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX, minNum = INT_MAX;
        priority_queue<int, vector<int>, less<int>> pq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2){
                nums[i] *= 2;
            }
            pq.push(nums[i]);
            minNum = min(minNum, nums[i]);
        }
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            ans = min(ans, top - minNum);
            if(top % 2){
                break;
            }
            pq.push(top/2);
            minNum = min(minNum, top/2);
        }
        return ans;
    }
};
// @lc code=end

