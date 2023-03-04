/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        stringstream stream;
        stream<<s;
        stack<string> stacks;
        string tmp;
        while(stream>>tmp){
            stacks.push(tmp);
        }
        string ans = "";
        bool isNotFirst = false;
        while(!stacks.empty()){
            if(isNotFirst){
                ans += " ";
            }
            isNotFirst = true;
            ans += stacks.top();
            stacks.pop();
        }
        return ans;
    }
};

// @lc code=end

