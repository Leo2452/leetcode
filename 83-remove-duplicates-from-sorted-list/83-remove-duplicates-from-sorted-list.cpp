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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) { return {}; }
        
        ListNode* unique_node = head;
        ListNode* front = head;
        head = head->next;
        while (head) {
            if (head->val == unique_node->val) { // remove dup
                unique_node->next = head->next;
            } else { // update unique node
                unique_node = head;
            }
            head = head->next;
        }
        return front;
    }
};