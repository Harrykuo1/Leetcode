/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    
    char ary[3000];
    int lps[3000];
    int len=0;
    int count;
    int ansIndex=0;
    int ansLen=0;
    string ans;
    string longestPalindrome(string s) {
        memset(ary,0,sizeof(ary));
        memset(lps,0,sizeof(lps));
        initString(s);
        manacher();
        /*
        for(int i=0;i<len;i++){
            printf("%d",lps[i]);
        }
        printf("\n\n");
        */
        ans="";
        for(int i=ansIndex-(ansLen-1);i<=ansIndex+(ansLen-1);i++){
            if(ary[i]=='#') continue;
            ans.push_back(ary[i]);
            //printf("%c",ary[i]);
        }
        //printf("\n\n");
        return ans;
    }
    
    void initString(string s){
        len=s.length();
        count=2;
        ary[0]='@';
        ary[1]='#';
        for(int i=0;i<len;i++){
            ary[count++]=s[i];
            ary[count++]='#';
        }
    }
    
    void manacher(){
        ansIndex=0;
        ansLen=0;
        int mid=1;
        len=strlen(ary);
        for(int i=2;i<len;i++){
            if(i<mid+lps[mid]){
                lps[i]=min(lps[2*mid-i],mid+lps[mid]-i);
            }
            else{
                lps[i]=1;
            }
            while(ary[i+lps[i]]==ary[i-lps[i]]){
                lps[i]++;
            }
            if(mid+lps[mid]<i+lps[i]){
                mid=i;
            }
            if(lps[i]>ansLen){
                ansIndex=i;
                ansLen=lps[i];
            }
        }
    }
    
};
// @lc code=end

