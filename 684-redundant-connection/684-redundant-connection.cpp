class UnionFind{
    vector<int> rank,parent;

    public:
    UnionFind(int sz):rank(sz),parent(sz){
       for(int i=0;i<sz;i++){
           rank[i]=0;
           parent[i]=i;
       }
   }
    
    int findp(int x){
        if(x==parent[x])
            return x;
        return parent[x]=findp(parent[x]);
    }
    
    void unionfind(int u,int v){
        u=findp(u);
        v=findp(v);
       
        if(u!=v){
        if(rank[u] < rank[v]){
            parent[u] =v;
        }
        
        else if(rank[u] > rank[v])
            parent[v]=u;
        
        else{
            parent[u]=v;
            rank[v]++;
        }
        }
    }
    
    bool isConnected(int u,int v){
        return findp(u)==findp(v);
    }
    

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(1001);
        vector<pair<int,int>> temp;
        
        for(int i=0;i<edges.size();i++){
            if(uf.isConnected(edges[i][0],edges[i][1])){
                temp.push_back({edges[i][0],edges[i][1]});
            }
            
            else{
                uf.unionfind(edges[i][0],edges[i][1]);
            }
        }
        
        vector<int> ans;
        int u=temp[temp.size()-1].first;
        int v=temp[temp.size()-1].second;
        
        ans.push_back(u);
        ans.push_back(v);
        return ans;
    }
};