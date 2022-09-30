/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long long int num=x;
        if(num>0){
            while(num%10==0){
                num/=10;
            }
            long long int ans=0;
            while(num){
                ans*=10;
                ans+=num%10;
                num/=10;
            }
            if(ans>2147483647){
                return 0;
            }
            return ans;
        }
        else if(num<0){
            while(num%10==0){
                num/=10;
            }
            num*=-1;
            long long int ans=0;
            while(num){
                ans*=10;
                ans+=num%10;
                num/=10;
            }
            printf("%lld\n",ans*-1);
            if(ans>2147483648){
                return 0;
            }
            return ans*-1;
        }
        else{
            return 0;
        }
    }
};

// @lc code=end

