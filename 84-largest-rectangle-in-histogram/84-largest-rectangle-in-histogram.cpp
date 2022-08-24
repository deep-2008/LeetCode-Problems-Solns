class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),ans=0;
        
       vector<int> ls(n,0),rs(n,0);
        stack<int> st,st1;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            
            if(st.size()>0){
                ls[i]=st.top()+1;
                st.push(i);
            }
            
            else{
                ls[i]=0;
                st.push(i);
            }
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && heights[st1.top()]>=heights[i])
                st1.pop();
            
            if(st1.size()>0){
                rs[i]=st1.top()-1;
                st1.push(i);
            }
            
            else{
                rs[i]=n-1;
                st1.push(i);
            }
        }
        
        for(int i=0;i<n;i++){
            int area=((rs[i]-ls[i]+1)*heights[i]);
            // cout<<area<<" ";
            ans=max(ans,area);
        }
        return ans;
    }
};