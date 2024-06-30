class MyStack {
public:
    stack<int> stk1;
    stack<int> stk2;
    MyStack() {}

    void push(int x) {
        stk1.push(x);
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
    }

    int pop() {
    int ele =stk2.top();
    stk2.pop();
    return ele; 
    }

    int top() {
    return stk2.top();
    }

    bool empty() { 
         return stk1.empty() && stk2.empty();
        }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */