class MyQueue {
    stack<int> s1;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
        
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
    }
    
    int pop() {
       
        stack<int> st;
        while(!s1.empty()){
            st.push(s1.top());
            s1.pop();
        }
        
        int x=st.top();
        st.pop();
        while(!st.empty()){
            s1.push(st.top());
            st.pop();
        }
        return x;
    }
    
    int peek() {
       stack<int> st,s=s1;
        
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        return st.top();
    }
    
    bool empty() {
        if(s1.size()>0)
            return 0;
        return 1;
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