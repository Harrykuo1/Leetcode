/*
 * @lc app=leetcode id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

// @lc code=start
class Solution {
public:
    int *dsu;
    void init_dsu(){
        dsu = (int *)malloc(26*sizeof(int));
        for(int i=0;i<26;i++){
            dsu[i] = i;
        }
    }

    int find_dsu(int n){
        if(dsu[n] == n){
            return n;
        }
        return dsu[n] = find_dsu(dsu[n]);
    }

    bool isSame(int a, int b){
        if(find_dsu(a) == find_dsu(b)){
            return true;
        }
        return false;
    }

    void union_dsu(int a, int b){
        if(find_dsu(a)>find_dsu(b)){
            a^=b; b^=a; a^=b;
        }
        if(!isSame(a,b)){
            dsu[find_dsu(b)] = find_dsu(a);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        init_dsu();  
        string ans = "";
        int len = s1.length();
        for(int i=0;i<len;i++){
            union_dsu(s1[i]-'a', s2[i]-'a');
        }
        len = baseStr.length();
        for(int i=0;i<len;i++){
            ans += find_dsu(baseStr[i]-'a') + 'a';
        }  
        printf("%d %d\n",dsu[0], dsu[1]);
        return ans;
    }
};
// @lc code=end

