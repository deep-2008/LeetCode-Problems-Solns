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
        // count--;
        }
    }
    
    // bool isConnected(int u,int v){
    //     return findp(u)==findp(v);
    // }
    
    // int getCount(){
        // return count;
    // }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf(200001);
        set<int> st;
        
        for(int i=0;i<stones.size();i++){
            uf.unionfind(stones[i][0],stones[i][1]+10001);
        }
        
        for(int i=0;i<stones.size();i++){
            st.insert(uf.findp(stones[i][0]));
        }
        
        return stones.size()-st.size();
    }
};