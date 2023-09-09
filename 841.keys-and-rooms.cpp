/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        set<int> s;
        for(int i=0;i<rooms[0].size();i++){
            s.insert(rooms[0][i]);
        }
        int now = 1;
        int pre = 0;
        int *check = (int *)malloc(n * sizeof(int));
        memset(check, false, sizeof(check));
        for(int i=0;i<n;i++){
            check[i] = false;
        }
        check[0] = true;
        while(pre != now){
            pre = now;
            for(auto it=s.begin(); it!=s.end(); it++){
                //printf("for: %d\n",*it);
                
                
                if(!check[*it]){
                    //printf("%d\n", *it);
                    check[*it] = true;
                    now++;
                    for(int i=0;i<rooms[*it].size();i++){
                        s.insert(rooms[*it][i]);
                    }
                }
            }
        }
        printf("now: %d\n",now);
        if(now == n){
            return true;
        }
        return false;
    }
};
// @lc code=end

