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

struct compare {
    bool operator()(ListNode const *n1, ListNode const *n2) {
        return (n1->val > n2->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector <ListNode*>, compare> pq;
        for (ListNode* list: lists) {
            if (list) pq.push(list);
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            if (head == NULL) {
                head = curr;
                tail = curr;
            } else {
                tail -> next = curr;
                tail = curr;
            }
            if (curr -> next) pq.push(curr -> next);
        }
        return head;
    }
};