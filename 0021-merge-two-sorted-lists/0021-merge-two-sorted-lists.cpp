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
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while (list1 && list2) {
            ListNode* curr = list1;
            if (list2 -> val < list1 -> val) {
                curr = list2;
                list2 = list2 -> next;
            } else {
                list1 = list1 -> next;
            }
            curr -> next = NULL;

            if (!head) {
                head = curr;
                tail = curr;
            } else {
                tail -> next = curr;
                tail = curr;
            }
        }
        if (!head) {
            if (!list1) return list2;
            return list1;
        }
        if (list1) tail -> next = list1;
        if (list2) tail -> next = list2;
        return head;
    }
};