/*
 * @lc app=leetcode id=2136 lang=cpp
 *
 * [2136] Earliest Possible Day of Full Bloom
 */

// @lc code=start
class Solution {
public:
    struct flower{
        int plantTime, growTime, total;
    };

    static bool cmp(flower a, flower b){
        return a.growTime > b.growTime;
    }

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<flower> arr;
        int n = plantTime.size();
        arr.resize(n);
        for(int i=0;i<n;i++){
            arr[i].plantTime = plantTime[i];
            arr[i].growTime = growTime[i];
        }
        sort(arr.begin(), arr.end(), cmp);
        int ans = -1;
        int prefix = 0;
        for(int i=0;i<n;i++){
            prefix += arr[i].plantTime;
            if(arr[i].growTime + prefix > ans){
                ans = arr[i].growTime + prefix;
            }
        }
        return ans;
    }
};
// @lc code=end

