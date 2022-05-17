class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto it:flights)
            adj[it[0]].push_back({it[1],it[2]});
        
        vector<int> cost(n,INT_MAX);
        vector<int> stops(n,INT_MAX);
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> minh;
        
        cost[src]=0;
        stops[src]=0;
        minh.push({0,src,0});
        
        while(!minh.empty()){
            auto [costs,source,stop]=minh.top();
            minh.pop();
            
            if(source==dst)
                return costs;
            if(stop==k+1)
                continue;
            
            for(auto [to,price]: adj[source]){
                if(costs+price <cost[to] || stop<stops[to]){
                    cost[to]=costs+price;
                     stops[to]=stop+1;
                    minh.push({cost[to],to,stops[to]});
                   
                    
                }
            }
        }
        return -1;
        
    }
};