class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n=nums.size();
        queue<int> q;
        set<int> vis;
        
        q.push(start);
        int step=0;
        
        while(!q.empty()){
            int size=q.size();
            step++;
            
            while(size-- >0){
                int node=q.front();
                q.pop();
                
                if(node==goal)
                    return step-1;
                
                if(node>1000 || node<0)
                    continue;
                
                if(vis.find(node)!= vis.end())
                    continue;
                
                vis.insert(node);
                
                for(int i=0;i<n;i++){                   
                        q.push(node+nums[i]);
                    
                        q.push(node-nums[i]);                    
                    
                        q.push(node^nums[i]);                    
                }
            }
        }
        return -1;
        
    }
};