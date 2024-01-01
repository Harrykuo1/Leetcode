/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
public:
    string makeGood(string s) {
        stack<char >stacks;
        int length = s.length();
        for(int i=0; i<length; i++){
            if(!stacks.empty() && toupper(stacks.top())==toupper(s[i]) && isupper(stacks.top())!=isupper(s[i])){
                stacks.pop();
            }
            else{
                stacks.push(s[i]);
            }
        }
        string ans = "";
        while(!stacks.empty()){
            ans+=stacks.top();
            stacks.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

