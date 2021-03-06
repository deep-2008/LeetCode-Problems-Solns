class MyStack {
    queue<int> q1,q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        // q2.push(x);
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        
        // while(!q2.empty()){
        //     q1.push(q2.front());
        //     q2.pop();
        // }
        
        q1.push(x);
        int n=q1.size();
        
        while(n-->1){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
       if(q1.size()>0)
           return 0;
        return 1;
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