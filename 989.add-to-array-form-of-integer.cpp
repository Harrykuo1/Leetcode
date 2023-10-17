/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry = 0;
        for(int i=num.size()-1;i>=0 || k>0;i--, k/=10){
            int tmp = k % 10 + carry;
            tmp += i>=0? num[i] : 0;
            carry = tmp/10;
            tmp%=10;
            ans.push_back(tmp);
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

