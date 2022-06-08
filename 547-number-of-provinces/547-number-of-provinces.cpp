class UnionFind{
    vector<int> rank,parent;
    int count;
    public:
    UnionFind(int sz):rank(sz),parent(sz),count(sz){
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
        count--;
        }
    }
    
    // bool isConnected(int u,int v){
    //     return findp(u)==findp(v);
    // }
    
    int getCount(){
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        
        UnionFind uf(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            
            if(isConnected[i][j]==1)
            uf.unionfind(i,j);
            
            }
        }
        
        return uf.getCount();
    }
};


