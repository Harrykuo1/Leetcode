/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ary;
        int l=0, r=0;
        while(l<nums1.size() && r<nums2.size()){
            if(nums1[l]<nums2[r]){
                ary.push_back(nums1[l]);
                l++;
            }
            else{
                ary.push_back(nums2[r]);
                r++;
            }
        }
        while(l<nums1.size()){
            ary.push_back(nums1[l]);
            l++;
        }
        while(r<nums2.size()){
            ary.push_back(nums2[r]);
            r++;
        }
        if(ary.size()%2){
            return ary[ary.size()/2];
        }
        else{
            return (ary[ary.size()/2] + ary[ary.size()/2-1])/2.0;
        }
    }
    
};
// @lc code=end

