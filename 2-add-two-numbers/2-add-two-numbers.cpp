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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode tmp(0);
        ListNode* result = &tmp;
        bool carry_over = false;
        while (l1 || l2 || carry_over) {
            int added = (l1? l1->val : 0) + (l2? l2->val : 0) + (carry_over? 1 : 0);
            carry_over = (added > 9);
            if (carry_over) {
                added = added % 10;
            }
            result->next = new ListNode(added);
            result = result->next;

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }

        return tmp.next;        
    }
};