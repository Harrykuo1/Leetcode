/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    int num,tmp;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode(0);
        ListNode *l=l1, *r=l2, *m=ans;
        tmp=0;
        while(l!=NULL || r!=NULL || tmp!=0){
            num=0;
            if(l!=NULL){
                num+=l->val;
                l=l->next;
            }
            if(r!=NULL){
                num+=r->val;
                r=r->next;
            }
            num+=tmp;
            tmp=num/10;
            num%=10;
            m->next=new ListNode(num);
            m=m->next;
        }
        return ans->next;
    }
};
// @lc code=end

