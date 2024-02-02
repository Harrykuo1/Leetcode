/*
 * @lc app=leetcode id=2359 lang=cpp
 *
 * [2359] Find Closest Node to Given Two Nodes
 */

// @lc code=start
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int *record1 = (int*)malloc(sizeof(int) * n);
        int *record2 = (int*)malloc(sizeof(int) * n);
        for(int i=0;i<n;i++){
            record1[i] = -1;
            record2[i] = -1;
        }
        record1[node1] = 0;
        while(edges[node1]!=-1 && record1[edges[node1]]==-1){
            record1[edges[node1]] = record1[node1]+1;
            node1 = edges[node1];
        }
        record2[node2] = 0;
        while(edges[node2]!=-1 && record2[edges[node2]]==-1){
            record2[edges[node2]] = record2[node2]+1;
            node2 = edges[node2];
        }
        int ansId = -1;
        int ansNum = 999999999;
        for(int i=0;i<n;i++){
            int tmp = max(record1[i], record2[i]);
            if(tmp<ansNum && record1[i]!=-1 && record2[i]!=-1){
                ansId = i;
                ansNum = tmp;
            }
        }
        return ansId;
    }
};
// @lc code=end

