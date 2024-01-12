/*
 * @lc app=leetcode id=2785 lang=cpp
 *
 * [2785] Sort Vowels in a String
 */

// @lc code=start
class Solution {
public:
    string sortVowels(string s) {
        set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        vector<char> vowels_vec;
        for(char &it : s){
            if(vowels.find(it) != vowels.end()){
                vowels_vec.push_back(it);
            }

        }
        sort(vowels_vec.begin(), vowels_vec.end());
        string ret = "";
        int idx = 0;
        for(char &it : s){
            if(vowels.find(it) != vowels.end()){
                ret += vowels_vec[idx++];
            }
            else{
                ret += it;
            }
        }
        return ret;
    }
};

// @lc code=end

