/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char >stacks;
        int length = s.length();
        for(int i=0; i<length; i++){
            if(!stacks.empty() && stacks.top()==s[i]){
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

