/*
 * @lc app=leetcode id=1255 lang=cpp
 *
 * [1255] Maximum Score Words Formed by Letters
 */

// @lc code=start
class Solution {
public:
    vector<int> resource;
    vector<int> cost;
    vector<vector<int>>letterArr;

    int ans = 0;

    void dfs(int now, int limit, int scoreNow){
        if(scoreNow > ans){
            ans = scoreNow;
        }
        if(now == limit){
            return;
        }
        for(int i=now;i<limit;i++){
            bool canUse = true;
            for(int j=0;j<26;j++){
                resource[j] -= letterArr[i][j];
                if(resource[j]<0){
                    canUse = false;
                }
            }
            if(canUse){
                dfs(i+1, limit, scoreNow + cost[i]);
            }
            for(int j=0;j<26;j++){
                resource[j] += letterArr[i][j];
            }
        }
        return;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        letterArr.resize(words.size());
        cost.resize(words.size());
        for(int i=0;i<words.size();i++){
            letterArr[i].resize(26);
            fill(letterArr[i].begin(), letterArr[i].end(), 0);
            for(int j=0;j<words[i].size();j++){
                letterArr[i][words[i][j]-'a']++;
                cost[i] += score[words[i][j]-'a'];
            }
        }

        resource.resize(26);
        for(int i=0;i<letters.size();i++){
            resource[letters[i]-'a']++;
        }

        dfs(0, words.size(), 0);
        
        return ans;
    }
};
// @lc code=end

