/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> tmpVec;

    bool isPalidrone(string s){
        int l=0, r=s.length()-1;
        while(l<r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void dfs(string s, int start, int limit){
        if(start == limit){
            ans.push_back(tmpVec);
        }
        for(int i=start;i<limit;i++){
            string tmpStr = s.substr(start, i-start+1);
            if(isPalidrone(tmpStr)){
                tmpVec.push_back(tmpStr);
                dfs(s, i+1, limit);
                tmpVec.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0, s.length());
        return ans;
    }
};
// @lc code=end

