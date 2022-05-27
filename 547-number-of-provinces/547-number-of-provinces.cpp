class UnionFind{
    vector<int> root,rank;
    int count;
    
    public:
    UnionFind(int sz): root(sz),rank(sz),count(sz){
        for(int i=0;i<sz;i++){
            root[i]=i;
            rank[i]=1;
        }
    }
    
    int find(int x){
        if(x==root[x])
            return x;
        return root[x]=find(root[x]);
    }
    
    void unionfind(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY])
                root[rootY]=rootX;
            
            else if(rank[rootX]<rank[rootY])
                root[rootX]=rootY;
            
            else{
                root[rootY]=rootX;
                rank[rootX]+=1;
            }
            count--;
        }
        
    }
    
    int getcount(){
        return (count);
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        
        if (n==0)
            return 0;
        UnionFind uf(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    uf.unionfind(i,j);
                }
            }
        }
        return uf.getcount();
        
    }
};