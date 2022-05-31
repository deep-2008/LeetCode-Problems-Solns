class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int t) {
        int c= jug1+jug2;
        
        queue<int> q;
        unordered_map<int,int> mp;
        q.push(0);
        mp[0]=1;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            int x1=node-jug1;
            int x2=node+jug1;
            
            int y1=node-jug2;
            int y2=node+jug2;
            
            if(x1>0 && mp[x1]==0){
                if(x1==t)
                    return true;
                q.push(x1);
                mp[x1]=1;
            }
            
            
            if(x2<=c && mp[x2]==0){
                if(x2==t)
                    return true;
                q.push(x2);
                mp[x2]=1;
            }
            
            
            if(y1>0 && mp[y1]==0){
                if(y1==t)
                    return true;
                q.push(y2);
                mp[y2]=1;
            }
            
            
            if(y2<=c && mp[y2]==0){
                if(y2==t)
                    return true;
                q.push(y2);
                mp[y2]=1;
            }
        }
        
        return false;
    }
};