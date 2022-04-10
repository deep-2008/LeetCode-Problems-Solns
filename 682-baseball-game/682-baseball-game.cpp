class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        int sum=0;
        stack<int> st;
        
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="D"){
                int x=st.top();
                st.push(2*x);
            }
            
            else if(ops[i]=="C"){
                st.pop();
            }
            
            else if(ops[i]=="+"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.push(x);
                st.push(x+y);
            }
            
            else
                st.push(stoi(ops[i]));
        }
        
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        
        return sum;
    }
};