/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slowPtr = head, *fastPtr = head;
        while(fastPtr && fastPtr->next){
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        return slowPtr;
    }
};
// @lc code=end

