/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        if(!mp[head]){
            mp[head] = new Node(head->val);
            mp[head]->next = copyRandomList(head->next); 
            mp[head]->random = copyRandomList(head->random);
        }
        return mp[head]; 
    }
};
// @lc code=end

