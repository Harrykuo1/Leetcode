/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, mid;
        while(l<=r){
            mid = (l+r)/2;
            if(mid % 2){
                if(nums[mid] == nums[mid-1]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if(mid + 1 >= n){
                    return nums[mid];
                }
                else if(nums[mid] == nums[mid+1]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return nums[l];
    }
};
// @lc code=end

