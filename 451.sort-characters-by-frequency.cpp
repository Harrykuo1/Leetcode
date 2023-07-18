/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
public:
    struct obj{
        char c;
        int num=0;
    };
    static bool cmp(obj a, obj b){
        return a.num>b.num;
    }
    string frequencySort(string s) {
        map<char, int>mp;
        int len = s.length();
        for(int i=0;i<len;i++){
            mp[s[i]]++;
        }
        vector<obj>vec;
        obj tmp;
        for(auto it=mp.begin();it!=mp.end();it++){
            tmp.c = it->first;
            tmp.num = it->second;
            vec.push_back(tmp);
        }
        sort(vec.begin(), vec.end(), cmp);
        string ans="";
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].num;j++){
                ans+=vec[i].c;
            }
        }
        return ans;
    }
};
// @lc code=end

