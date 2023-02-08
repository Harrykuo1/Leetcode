/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s){
        if(s.length()>3 || stoi(s) > 255 || (s[0] == '0' && s.length()>1)){
            return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int len = s.length();
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    if(i+j+k<len && i+j+k+3>=len){
                        string a = s.substr(0,i);
                        string b = s.substr(i,j);
                        string c = s.substr(i+j,k);
                        string d = s.substr(i+j+k);
                        if(isValid(a) && isValid(b) && isValid(c) && isValid(d)){
                            string tmp = a + '.' + b + '.' + c + '.' + d;
                            ans.push_back(tmp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// @lc code=end

