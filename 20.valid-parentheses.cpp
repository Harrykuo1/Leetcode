/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isRight(char c){
        if(c==')' || c==']' || c=='}'){
            return true;
        }
        return false;
    }

    bool isPair(char a, char b){
        if(a=='(' && b == ')'){
            return true;
        }
        if(a=='[' && b == ']'){
            return true;
        }
        if(a=='{' && b == '}'){
            return true;
        }
        return false;
    }

    bool isValid(string s) {
        int length = s.length();
        stack<char>stacks;
        for(int i=0;i<length;i++){
            if(stacks.empty()){
                if(isRight(s[i])){
                     return false;
                }
                else{
                    stacks.push(s[i]);
                }
            }
            else{
                char top = stacks.top();
                if(isRight(s[i])){
                    if(isPair(top,s[i])){
                        stacks.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    stacks.push(s[i]);
                }
            }
        }
        if(stacks.size() == 0){
            return true;
        }
        return false;
    }
};
// @lc code=end

