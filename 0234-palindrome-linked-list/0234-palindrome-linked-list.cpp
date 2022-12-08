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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode* newHead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head -> next) return true;
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* reversedList = reverseList(slow -> next);
        slow -> next = NULL;
        while (head && reversedList) {
            if (head -> val != reversedList -> val) {
                return false;
            }
            head = head -> next;
            reversedList = reversedList -> next;
        }
        return true;
    }
};