// class Solution {
//     void dfs(vector<vector<int>>& grid,int n,int row){
//         for(int i=0;i<n;i++){
//             if(grid[row][i]==0)
//                 grid[row][i]=1;
            
//             else
//                 grid[row][i]=0;
//         }
//     }
    
//    void dfs2(vector<vector<int>>& grid,int m,int col){
//         for(int i=0;i<m;i++){
//             if(grid[i][col]==0)
//                 grid[i][col]=1;
            
//             else
//                 grid[i][col]=0;
//         }
//     }
// public:
//     int matrixScore(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//          int ans=0,ans2=0,ans1=0;
        
//         //row
//         for(int i=0;i<m;i++){
//             if(grid[i][0]==0)
//                 dfs(grid,n,i);
//         }
        
//         if(m>=n){
//             for(int i=0;i<n;i++){
//                 int sum=0,k=m-1;
//                 for(int j=0;j<m;j++){
//                     sum=sum+grid[j][i]*(1<<k);
//                     k--;
//                 }
//                 ans1+=sum;
//             }
//         }
        
//         else{
//             for(int i=0;i<m;i++){
//                 int sum=0,k=n-1;
//                 for(int j=0;j<n;j++){
//                     sum=sum+grid[i][j]*(1<<k);
//                     k--;
//                 }
//                 ans1+=sum;
//             }
//         }
        
//         //column
//         for(int i=0;i<n;i++){
//             if(grid[0][i]==0)
//                 dfs2(grid,m,i);
//         }
       
//         if(m>=n){
//             for(int i=0;i<n;i++){
//                 int sum=0,k=m-1;
//                 for(int j=0;j<m;j++){
//                     sum=sum+grid[j][i]*(1<<k);
//                     k--;
//                 }
//                 ans2+=sum;
//             }
//         }
        
//         else{
//             for(int i=0;i<m;i++){
//                 int sum=0,k=n-1;
//                 for(int j=0;j<n;j++){
//                     sum=sum+grid[i][j]*(1<<k);
//                     k--;
//                 }
//                 ans2+=sum;
//             }
//         }
        
//         return max(ans1,ans2);
//     }
// };


























class Solution {
public:
    
    int sum(vector<vector<int>> mat){
        int score = 0;
        
        
        
        for(int i=0;i<mat.size();i++){
            int p = mat[0].size()-1;
            for(int j=0;j<mat[0].size();j++){
                score+= mat[i][j]*pow(2,p);
                p--;
            }
        }
        
        return score;
    }
    
    int matrixScore(vector<vector<int>>& grid) {
//         if(grid.size()==1){
//             return ;
//         }
        
        
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==0){
               for(int j=0;j<grid[0].size();j++){
                   if(grid[i][j]==0){
                       grid[i][j]=1;
                   }
                   else{
                        grid[i][j]=0;
                   }
               }
            }
        }
        
        
        
        
        vector<int> ind;
        
        for(int i=1;i<grid[0].size();i++){
            int ct=0;
            for(int j=0;j<grid.size();j++){
                ct+=grid[j][i];
               
            }
            if(ct<=grid.size()/2){
                ind.push_back(i);
            }
        }
        // for(auto v:ind){
            // cout<<v<<" ";
        // }
        
        for(auto c:ind){
            for(int j=0;j<grid.size();j++){
                if(grid[j][c]==0){
                       grid[j][c]=1;
                   }
                   else{
                        grid[j][c]=0;
                   }
            }
        }

        return sum(grid);   
    }
};