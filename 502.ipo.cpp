/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
public:
    struct Task{
        int profit, capital;
    }tmp;

    static bool cmp(Task a, Task b){
        return a.capital < b.capital;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), indexNow = 0, ans = w;
        vector<Task> taskVec(n);
        priority_queue<int, vector<int>, less<int>>pq;
        for(int i=0;i<n;i++){
            taskVec[i].profit = profits[i];
            taskVec[i].capital = capital[i];
        }
        sort(taskVec.begin(), taskVec.end(), cmp);
        for(int i=0;i<k;i++){
            while(indexNow<n && taskVec[indexNow].capital<=ans){
                pq.push(taskVec[indexNow].profit);
                indexNow++;
            }
            if(!pq.empty()){
                ans += pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

