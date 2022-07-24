class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size(),ans=0;
        unordered_map<string,int> mp;
        
        for(int i=0;i<n;i++){
            string temp="";
            
            for(int j=0;j<n;j++)
                temp+=grid[i][j];
            
            mp[temp]++;
        }
        
         for(int i=0;i<n;i++){
            string temp="";
            
            for(int j=0;j<n;j++)
                temp+=grid[j][i];
            
            ans+=mp[temp];
        }
        return ans;
    }
};