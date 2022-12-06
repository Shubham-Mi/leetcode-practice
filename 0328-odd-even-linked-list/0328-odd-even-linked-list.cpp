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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode* evenHead = head -> next;
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* curr = head -> next -> next;
        bool oddNode = true;
        while (curr) {
            if (oddNode) {
                odd -> next = curr;
                odd = odd -> next;
            } else {
                even -> next = curr;
                even = even -> next;
            }
            oddNode = !oddNode;
            curr = curr -> next;
        }
        odd -> next = evenHead;
        even -> next = NULL;
        return head;
    }
};