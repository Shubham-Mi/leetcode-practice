/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* newHead = NULL;
        Node* newTail = NULL;
        unordered_map<Node*, Node*>mp;
        Node* temp = head;
        while (temp != NULL) {
            Node* curr = new Node(temp -> val);
            mp[temp] = curr;
            temp = temp -> next;
            if (!newHead) {
                newHead = curr;
                newTail = curr;
            } else {
                newTail -> next = curr;
                newTail = curr;
            }
        }
        temp = head;
        while (temp != NULL) {
            if (temp -> random) mp[temp] -> random = mp[temp -> random];
            temp = temp -> next;
        }
        return newHead;
    }
};