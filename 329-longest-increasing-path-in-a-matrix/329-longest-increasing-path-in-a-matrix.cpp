class Solution {
public:
    vector<vector<int>> dirs= {{-1,0},{0,-1},{1,0},{0,1}};
    
    int dfs(int r,int c, vector<vector<int>>& matrix,vector<vector<int>>& dp,int prev){
        if(r<0 || r>=matrix.size())
            return 0;
        if(c<0 || c>=matrix[r].size())
            return 0;
        if(matrix[r][c]<=prev)
            return 0;
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        int best=0;
        
        for(auto it:dirs){
            int nr=it[0]+r;
            int nc=it[1]+c;
            int cur=dfs(nr,nc,matrix,dp,matrix[r][c]);
            best=max(best,cur);
        }
        
        return dp[r][c]=best+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        vector<vector<int>> dp(row,vector<int>(col,-1));
        
        int ans=0;
        
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                int lip=dfs(r,c,matrix,dp,-1000000);
                ans=max(ans,lip);
            }
        }
        
        return ans;
    }
};