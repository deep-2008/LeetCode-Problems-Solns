class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<char> choice={'A','C','G','T'};
      
        set<string> vis;
        queue<string> q;
        
        sort(bank.begin(),bank.end()); //for binary search
        
        q.push(start);
        vis.insert(start);
        
        int level=-1;
        
        while(!q.empty()){
            level++;
            int size=q.size();
            
            while(size-->0){
                string node=q.front();
                q.pop();
                
                if(node==end)
                    return level;
                
                for(int i=0;i<start.size();i++){
                    char x=node[i]; //or we can store the ASCII i.e., int x=node[i];
                    //cout<<x<<" ";
                    
                    for(int j=0;j<4;j++){
                        node[i]=choice[j];
                        
                       if(binary_search(bank.begin(),bank.end(),node) && vis.count(node)!=1){
                           vis.insert(node);
                           q.push(node);
                       }
                    }
                    node[i]=x;
                }
            }
        }
        
        return -1;
    }
};