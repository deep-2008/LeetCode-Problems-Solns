//KRUSKAL'S ALGO
class UnionFind{
    vector<int> root,rank;
    
    
    public:
    UnionFind(int sz): root(sz),rank(sz){
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
    
    bool unionfind(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
       if(rootX == rootY)
           return false;
        
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY])
                root[rootY]=rootX;
            
            else if(rank[rootX]<rank[rootY])
                root[rootX]=rootY;
            
            else{
                root[rootY]=rootX;
                rank[rootX]+=1;
            }
                    }
        return true;
        
    }
    
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        UnionFind uf(points.size());
        int n=points.size();
        vector<pair<int,pair<int,int>>> allEdges;
        
        
          for (int currNode = 0; currNode < n; ++currNode) {
            for (int nextNode = currNode + 1; nextNode < n; ++nextNode) {
                int weight = abs(points[currNode][0] - points[nextNode][0]) + 
                             abs(points[currNode][1] - points[nextNode][1]);
                
                allEdges.push_back({ weight, { currNode, nextNode }});
            }
        }
        
        // Sort all edges in increasing order.
        sort(allEdges.begin(), allEdges.end());
        int cost=0,edgesUsed=0;
        
        for(int i=0;i<allEdges.size() && edgesUsed<n-1;i++){
            int node1 = allEdges[i].second.first;
            int node2= allEdges[i].second.second;
            int wt=allEdges[i].first;
            
            if(uf.unionfind(node1,node2)){
                cost+=wt;
                edgesUsed++;
            }
        }
        return cost;
    }
};