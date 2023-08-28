class MyStack {
public:
    
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        
       q2 = {};
        
       while(q1.size() > 1){
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        
        int temp = q1.front();
        q1 = q2;
        
        return temp;
    }
    
    int top() {
        q2 = {};
        
        while(q1.size() > 1){
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        
        int temp = q1.front();
        q1.pop();
        q2.push(temp);
        q1 = q2;
        return temp;
    }
    
    bool empty() {
        return q1.size() == 0;
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