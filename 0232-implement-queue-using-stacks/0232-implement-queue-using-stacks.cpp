class MyQueue {
    stack <int> stk1, stk2;
    void balance() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
    }
public:
    MyQueue() {
        while (!stk1.empty()) {
            stk1.pop();
        }
        while (!stk2.empty()) {
            stk2.pop();
        }
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        balance();
        int ans = stk2.top();
        stk2.pop();
        return ans;
    }
    
    int peek() {
        balance();
        return stk2.top();
    }
    
    bool empty() {
        balance();
        return stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */