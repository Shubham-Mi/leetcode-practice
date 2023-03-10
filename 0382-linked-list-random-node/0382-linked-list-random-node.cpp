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
    vector <ListNode*> nodes;
    int sz = 0;
public:
    Solution(ListNode* head) {
        while (head) {
            nodes.push_back(head);
            head = head -> next;
            sz++;
        }
    }
    
    int getRandom() {
        return nodes[rand() % sz] -> val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */