/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        int *arr = (int*)malloc(sizeof(int)*(50));
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        for(int i=3;i<=n;i++){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }
        return arr[n];
    }
};
// @lc code=end

