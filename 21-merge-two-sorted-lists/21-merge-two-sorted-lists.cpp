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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) { return list2; }
        if (!list2) { return list1; }
        
        ListNode tmp(0);
        ListNode* result = &tmp;
        while (list1 || list2) {
            bool advance_list1 = false;
            int next_val;
            if (!list1) {
                next_val = list2->val;
            } else if (!list2) {
                next_val = list1->val;
                advance_list1 = true;
            } else if (list1->val < list2->val) { // both exist - compare and assign values
                next_val = list1->val;
                advance_list1 = true;                
            } else {
                next_val = list2->val;
            }
            result->next = new ListNode(next_val);
            result = result->next;
            
            if (advance_list1) {
                list1 = list1->next;
            } else {
                list2 = list2->next;
            }
        }
        return tmp.next;
    }
};