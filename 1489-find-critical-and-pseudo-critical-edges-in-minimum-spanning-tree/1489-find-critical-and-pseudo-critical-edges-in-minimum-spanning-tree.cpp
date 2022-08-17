// class UnionFind{
//     vector<int> rank,parent;
//     public:
//     UnionFind(){
//         for(int i=0;i<1005;i++){
//             rank.push_back(0);
//             parent.push_back(i);
//         }
//     }
    
//     int findPar(int node){
//         if(node==parent[node])
//         return node;
        
//         return parent[node]=findPar(parent[node]);
//     }
    
//     void unionfind(int u,int v){
//         u=findPar(u);
//         v=findPar(v);
        
//         if(rank[u]<rank[v])
//         parent[u]=v;
        
//         else if(rank[u]>rank[v])
//         parent[v]=u;
        
//         else{
//             parent[u]=v;
//             rank[v]++;
//         }
//     }
// };

// bool comp(vector<int> a,vector<int> b){
//     return a[2]<b[2];
// }

// int actualCost=0;
// class Solution {
//    void checkMST(vector<vector<int>>& edges,int n,int &cost,set<int>& st){
//        UnionFind uf;
//         sort(edges.begin(),edges.end(),comp);
//        // int cost=0;
       
//        for(int i=0;i<edges.size();i++){
//            int u=edges[i][0];
//            int v=edges[i][1];
//            int wt=edges[i][2];
           
//            if(uf.findPar(u)!=uf.findPar(v)){
//                cost+=wt;
//                uf.unionfind(u,v);
//                st.insert(i);
//            }
//        }
//        // cout<<cost;
//     }
// public:
//     vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
//         int cost=0;
//         //CHECKING COST OF ACTUAL MST
//         set<int> st;
//         checkMST(edges,n,cost,st);
//         actualCost=cost;
        
//         vector<vector<int>> ans(2);
        
//         //FINDING THE CRITICAL EDGES
//         int m=0;
//         map<int,int> mp;
//         while(m<edges.size()){
//             vector<vector<int>> copy(edges);
//             copy.erase(copy.begin()+m);
//             int temp=0;
//             copy.pop_back();
//             set<int> dummy;
//             checkMST(copy,copy.size(),temp,dummy);
            
//             // cout<<temp<<" ";
//             if(temp>cost){
//                 ans[0].push_back(m);
//                 mp[m]=1;
//             }
                      
//             m++;
//         }
        
//         vector<vector<int>> helper;
//         for(auto it:st){
//             if(mp.find(it)==mp.end()){
//                 st.erase(it);
//                 break;
//             }
//         }
        
//         for(auto it:st){
//             vector<int> temp;
//             int u=edges[it][0];
//             int v=edges[it][1];
//             int wt=edges[it][2];
//             temp.push_back(u);
//              temp.push_back(v);
//              temp.push_back(wt);
//             helper.push_back(temp);
            
//         }
        
        
//         set<int> d;
//         for(int i=0;i<edges.size();i++){
//              vector<int> temp;
//             int u=edges[i][0];
//             int v=edges[i][1];
//             int wt=edges[i][2];
//             temp.push_back(u);
//              temp.push_back(v);
//              temp.push_back(wt);
//             helper.push_back(temp);
//              vector<vector<int>> copyHelper(helper);        
            
//             int tempCost=0;
//             checkMST(copyHelper,copyHelper.size(),tempCost,d);
            
//             cout<<tempCost<<" ";
//             if(tempCost==actualCost)
//                 ans[1].push_back(i);
            
//             helper.pop_back();
//             // for(auto it:helper)
//             // cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<" "<<endl; 
//             // break;
//         }
        
//         return ans;
//     }
// };


class UnionFind {
public:
    UnionFind(int n) {
        rank = vector<int>(n, 1);
        f.resize(n);
        for (int i = 0; i < n; ++i) f[i] = i;
    }
    
    int Find(int x) {
        if (x == f[x]) return x;
        else return f[x] = Find(f[x]);
    }
    
    void Union(int x, int y) {
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        f[fx] = fy;
        if (rank[fx] == rank[fy]) rank[fy]++;
    }
    
private:
    vector<int> f, rank;
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int origin_mst = GetMST(n, edges, -1);
        vector<int> critical, non_critical;
        for (int i = 0; i < edges.size(); ++i) {
            if (origin_mst < GetMST(n, edges, i)) {
                critical.push_back(edges[i][3]);
            } else if (origin_mst == GetMST(n, edges, -1, i)) {
                non_critical.push_back(edges[i][3]);
            }
        }
        return {critical, non_critical};
    }
    
private:
    int GetMST(const int n, const vector<vector<int>>& edges, int blockedge, int pre_edge = -1) {
        UnionFind uf(n);
        int weight = 0;
        if (pre_edge != -1) {
            weight += edges[pre_edge][2];
            uf.Union(edges[pre_edge][0], edges[pre_edge][1]);
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (i == blockedge) continue;
            const auto& edge = edges[i];
            if (uf.Find(edge[0]) == uf.Find(edge[1])) continue;
            uf.Union(edge[0], edge[1]);
            weight += edge[2];
        }
        for (int i = 0; i < n; ++i) {
            if (uf.Find(i) != uf.Find(0)) return 1e9+7;
        }
        return weight;
    }
};