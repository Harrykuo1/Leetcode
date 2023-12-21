/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

// @lc code=start
class Solution {
public:
    struct node{
        int num;
        int deep;
        bool operator<(const node &rhs)const{ return deep<rhs.deep; }
    };
    node head, tmp;
    int *deepArr;
    vector<vector<int>> hasEdge;

    priority_queue<node, vector<node>>pq;
    void dfs(int now){
        for(int i=0;i<hasEdge[now].size();i++){
            if(deepArr[hasEdge[now][i]] == -1){
                deepArr[hasEdge[now][i]] = deepArr[now] + 1;
                tmp.num = hasEdge[now][i];
                tmp.deep = deepArr[hasEdge[now][i]];
                pq.push(tmp);
                dfs(hasEdge[now][i]);
            }
        }
        return;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>ans;
        ans.resize(n+1);
        for(int i=0;i<ans.size();i++){
            ans[i].resize(27);
        }

        deepArr = (int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++){
            deepArr[i] = -1;
            ans[i][labels[i]-'a']++;
        }
        deepArr[0] = 0;
        tmp.num = 0;
        tmp.deep = 0;
        pq.push(tmp);

        
        hasEdge.resize(n+1);
        for(int i=0;i<edges.size();i++){
            hasEdge[edges[i][0]].push_back(edges[i][1]);
            hasEdge[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(0);
        while(!pq.empty()){
            head = pq.top();
            pq.pop();
            for(int i=0;i<hasEdge[head.num].size();i++){
                if(deepArr[hasEdge[head.num][i]] > deepArr[head.num]){
                    for(int j=0;j<26;j++){
                        ans[head.num][j] += ans[hasEdge[head.num][i]][j];
                    }
                }
            }
        }
        vector<int> ansVec;
        for(int i=0;i<n;i++){
            ansVec.push_back(ans[i][labels[i]-'a']);
        }
        return ansVec;
    }
};
// @lc code=end

