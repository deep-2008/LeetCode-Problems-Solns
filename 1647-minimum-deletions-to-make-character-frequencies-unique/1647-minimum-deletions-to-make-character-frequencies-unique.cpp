class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        priority_queue<int> maxh;
        
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        
        for(auto it:mp){
            maxh.push(it.second);
            // cout<<maxh.top();
        }
        
        int ans=0,prev=-1;
        
        while(maxh.size()>0){
            int x=maxh.top();
            maxh.pop();
            
            if(prev!=-1){
                if(x==prev){
                    prev=x;
                    ans++;
                    x--;
                    
                    if(x>0)
                    maxh.push(x);
                }
                else
                    prev=x;
            }
            else if(prev==-1)
            prev=x;
        }
        
        return ans;
    }
};