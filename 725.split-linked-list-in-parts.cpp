/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int len = 0;
        ListNode* old = head;
        while(old != NULL){
            len++;
            old = old->next;
        }

        old = head;
        for(int i=0;i<k;i++){
            ListNode* tmp = new ListNode(0); 
            ans[i] = tmp;
            for(int j=0;j<len/k && old!=NULL;j++){
                tmp->next = new ListNode(old->val);
                tmp = tmp->next;
                old = old->next;
            }
            if(i < len % k){
                tmp->next = new ListNode(old->val);
                tmp = tmp->next;
                old = old->next;
            }
            ans[i] = ans[i]->next;
        }

        return ans;
    }
};
// @lc code=end

