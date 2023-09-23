/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0, ans = 0;
        map<int, int> mp;
        for(int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;
            while(mp.size()>2){
                mp[fruits[start]]--;
                if(mp[fruits[start]] == 0){
                    mp.erase(fruits[start]);
                }
                start++;
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};
// @lc code=end

