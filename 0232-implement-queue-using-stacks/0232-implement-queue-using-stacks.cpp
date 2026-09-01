class MyQueue {
    stack<int> input;
    stack<int> output;
    int first=-1;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){
            first=x;
        }
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int x=output.top();
        output.pop();
        return x;
    }
    
    int peek() {
        if(output.empty()) return first;
        return output.top();
    }
    
    bool empty() {
        if(output.empty() && input.empty()) return true;
        else return false;
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