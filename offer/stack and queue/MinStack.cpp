#include <iostream>
#include <stack>
using namespace std;
class MinStack {
private:
    stack<int> save_stack;
    stack<int> min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        save_stack.push(x);
        if (min_stack.empty()||x<=min_stack.top())//must <=;有可能push重复的最小元素
        {
            min_stack.push(x);
        }
        
    }
    
    void pop() {
        int pop_value = save_stack.top();
        save_stack.pop();
        if (pop_value==min_stack.top())
        {
            min_stack.pop();
        }
        
    }
    
    int top() {
        return save_stack.top();
    }
    
    int min() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */