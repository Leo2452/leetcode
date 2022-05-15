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

using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode tmp(0);
        ListNode* result = &tmp;
        bool carry_over = false;
        while (l1 && l2) {
            int added = (l1->val + l2->val) + (carry_over ? 1 : 0);
            carry_over = (added > 9);
            if (carry_over) {
                added = added % 10;
            }
            result->next = new ListNode(added);
            result = result->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* remains = (l1 == nullptr) ? l2 : l1;
        while (remains) {
            int added = remains->val + (carry_over ? 1 : 0);
            carry_over = (added > 9);
            if (carry_over) {
                added = added % 10;
            }
            result->next = new ListNode(added);
            result = result->next;

            remains = remains->next;
        }
        if (carry_over) {
            result->next = new ListNode(1);
            result = result->next;
        }
        return tmp.next;
        
    }
};