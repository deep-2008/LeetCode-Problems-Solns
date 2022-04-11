class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int p=m*n;
        k=k%p;
        vector<int> ans;
        
        if(m==1 && n==1)
            return grid;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans.push_back(grid[i][j]);
            }
        }
        
        
        vector<int> temp;
        for(int i=p-k;i<p;i++)
            temp.push_back(ans[i]);
        
        for(int i=0;i<p-k;i++)
            temp.push_back(ans[i]);
        int i=0,j=0;
        vector<vector<int>> result;
        int vec=0;
       for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = temp[vec];
                vec++;
            }
        }
        
        return grid;
       
    }
};