/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
int removeDuplicates(int* nums, int numsSize){
    int nows = -2147483648;
    int ptr = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=nows){
            nums[ptr] = nums[i];
            nows = nums[ptr];
            ptr++;
        }
    }   
    return ptr; 
}
// @lc code=end

