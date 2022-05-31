class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
       /* string start="0000";
        
        set<string> vis;
        queue<string> q;
        
        sort(deadends.begin(),deadends.end()); //for binary search
        
        q.push(start);
        vis.insert(start);
        
        int level=-1;
        
        while(!q.empty()){
            level++;
            int size=q.size();
            
            while(size-- >0){
                string node=q.front();
                q.pop();
                
                if(node == target)
                    return level;
                
                for(int i=0;i<4;i++){
                    int x=node[i];
                    
                    for(char c='0';c<='9';c++){
                        node[i]=c;
                        
                        if(binary_search(deadends.begin(),deadends.end(),node))
                            continue;
                        if(vis.count(node)==1)
                            continue;
                        
                            q.push(node);
                            vis.insert(node);
                        
                    }
                    node[i]=x;
                }
            }
        }
        
        return -1;*/
        
        
        unordered_map<string,bool> mp;
        for(auto a:deadends)
            mp[a]=1;
        
        queue<string> q;
        q.push("0000");
        map<string,bool> visited;
        int cost=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                string curr=q.front();
                q.pop();
                
                if(mp[curr] || visited[curr]) 
                    continue;
                
                visited[curr]=true;
                // cout<<curr<<" ";
                
                if(curr==target)
                    return cost;
                
                for(int i=0;i<4;i++)
                {
                    string c=curr;
                        int j=c[i]-'0';
                        int k=j;
                    
                        j++;
                        j%=10;
                        c[i]=(j+'0');
                        if(!mp[c] && !visited[c])
                            q.push(c);
                        
                        k--;
                        k+=10;
                        k%=10;

                        c[i]=(k+'0');
                        if(!mp[c] && !visited[c])
                            q.push(c);
                    
                        
                }
                
                
            }
            cost++;
        }
        
        return -1;
    }
};