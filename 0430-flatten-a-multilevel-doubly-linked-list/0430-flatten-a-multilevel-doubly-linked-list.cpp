/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack <Node*> stk;
        Node* curr = head;
        Node* prv = NULL;
        while (curr) {
            if (prv) {
                prv -> next = curr;
                curr -> prev = prv;
            }
            prv = curr;

            if (curr -> child) {
                Node* childNode = curr -> child;
                if (curr -> next) stk.push(curr -> next);
                curr -> child = NULL;
                curr = childNode;
                continue;
            } else {
                curr = curr -> next;
                if (!curr) {
                    if (stk.empty()) break;
                    curr = stk.top();
                    stk.pop();
                }
            }
        }
        return head;
    }
};