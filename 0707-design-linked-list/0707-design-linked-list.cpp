struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

class MyLinkedList {
    Node* head;
    Node* tail;
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int index) {
        if (!head) return -1;
        Node* ans = head;
        for (int i=0; i<index; ++i) {
            ans = ans -> next;
            if (!ans) return -1;
        }
        return ans -> val;
    }
    
    void addAtHead(int val) {
        Node* newHead = new Node(val);
        newHead -> next = head;
        head = newHead;
        if (!tail) tail = newHead;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        if (!tail) {
            head = node;
            tail = node;
        } else {
            tail -> next = node;
            tail = tail -> next;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (!head) return;
        Node* prv = head;
        for (int i=0; i<index-1; ++i) {
            prv = prv -> next;
            if (!prv) return;
        }
        if (prv == tail) {
            addAtTail(val);
            return;
        }
        Node* node = new Node(val);
        node -> next = prv -> next;
        prv -> next = node;
    }
    
    void deleteAtIndex(int index) {
        if (index == 0) {
            Node* deleteNode = head;
            if (tail == head) tail = nullptr;
            head = head -> next;
            delete deleteNode;
            return;
        }
        Node* prv = head;
        for (int i=0; i<index-1; ++i) {
            prv = prv -> next;
            if (!prv) return;
        }
        if (!prv -> next) return;
        if (prv -> next == tail) {
            tail = prv;
        }
        Node* deleteNode = prv -> next;
        prv -> next = prv -> next -> next;
        delete deleteNode;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */