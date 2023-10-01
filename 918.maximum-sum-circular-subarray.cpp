/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int Gmin=nums[0], Gmax=nums[0], sum=nums[0], Lmin=nums[0], Lmax=nums[0];
        for(int i=1;i<nums.size();i++){
            Lmax = max(Lmax+nums[i], nums[i]);
            Gmax = max(Lmax, Gmax);
            Lmin = min(Lmin+nums[i], nums[i]);
            Gmin = min(Lmin, Gmin);
            sum += nums[i];
        }
        printf("%d %d %d\n",sum ,Gmin, Gmax);
        return Gmax>=0 ? max(Gmax, sum - Gmin) : Gmax ;
    }
};
// @lc code=end

