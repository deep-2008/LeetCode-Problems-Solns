class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<vector<int>> st;
unordered_map<int,int> m;
for(int i=0;i<roads.size();i++){
st.insert(roads[i]);
m[roads[i][0]]++;
m[roads[i][1]]++;
}
int ans = INT_MIN;
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if(st.find({i,j})!=st.end() || st.find({j,i})!=st.end()){
ans = max(ans,m[i]+m[j]-1);
}
else{
ans = max(ans,m[i]+m[j]);
}
}
}
return ans;
    }
};