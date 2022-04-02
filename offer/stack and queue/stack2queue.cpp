#include <iostream>
#include <stack>
using namespace std;
class CQueue {
private:
    stack<int> instack,outstack;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        instack.push(value);
    }
    
    int deleteHead() {
        if (outstack.empty())
        {
            while (!instack.empty())
            {
                outstack.push(instack.top());
                instack.pop();
            }
            
        }
        if (outstack.empty())
        {
            return -1;
        }
        else{
            int value = outstack.top();
            outstack.pop();
            return value;
        }
        
        
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
