/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    bool isVowel(char c){
        bool ans = false;
        char arr[]={'a','e','i','o','u'};
        for(int i=0;i<5;i++){
            if(tolower(c) == arr[i]){
                ans = true;
            }
        }
        return ans;
    }
    string reverseVowels(string s) {
        int l=0, r=s.length();
        while(l<r){
            while(!isVowel(s[l]) && l<r){
                l++;
            }
            while(!isVowel(s[r]) && l<r){
                r--;
            }
            if(isVowel(s[l]) && isVowel(s[r]) && l<r){
                s[l]^=s[r];
                s[r]^=s[l];
                s[l]^=s[r];
            }
            l++;
            r--;
        }
        return s;
    }
};

// @lc code=end

