/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        unordered_map<int, ListNode*> ump;
        int idx = 0;
        ListNode* zero = new ListNode(0);
        ListNode* tmp = zero;
        tmp->next = head;
        while(idx < left-1){
            tmp = tmp->next;
            idx++;
        }
        for(int i=left-1;i<=right+1;i++){
            ump[i] = tmp;
            if(tmp) tmp = tmp->next;
        }
        ump[left-1]->next = ump[right];
        for(int i=right;i>left;i--){
            ump[i]->next = ump[i-1];
        }
        ump[left]->next = ump[right+1];
        return zero->next;
    }
};
// @lc code=end

