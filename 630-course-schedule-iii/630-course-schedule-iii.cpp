class Solution {
   static bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        int days=0;
        
        priority_queue<int> maxh;
        sort(courses.begin(),courses.end(),comp);
        
        for(int i=0;i<n;i++){
            int u=courses[i][0];
            int v=courses[i][1];
            days+=u;
            maxh.push(u);
            
            if(days>v){
                days-=maxh.top();
                maxh.pop();
            }
            
           
        }     
    
        return maxh.size();
    }
};