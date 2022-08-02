class Solution {
    int dp[201][201];
    int solve(vector<vector<int>>& dungeon,int row,int col,int m,int n,int &temp){
        if(row==m || col==n)
            return 1e9;
        
        if(row==m-1 && col==n-1)
              return (dungeon[row][col] <= 0) ? -dungeon[row][col] + 1 : 1;
        
        if(dp[row][col]!=0)
            return dp[row][col];
        
       long long int a,b;        
         a=-dungeon[row][col]+solve(dungeon,row+1,col,m,n,temp);
         b=-dungeon[row][col]+solve(dungeon,row,col+1,m,n,temp);
        
        int res=min(a,b);
        
        return dp[row][col]=(res<=0)?1:res;
    }
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size(),temp=0;
        memset(dp,0,sizeof(dp));
    
        return solve(dungeon,0,0,m,n,temp);
    }
};