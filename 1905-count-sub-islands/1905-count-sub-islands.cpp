#define vii vector<vector<int>>
class Solution {
public:
    bool flag=true;
    void floodfill(vii &g2,int r,int c,vii &vis, vii &g1){
        if(r<0 || c<0 || r==g2.size() || c==g2[0].size() || g2[r][c]==0 )
            return ;
        
        if(g1[r][c]==0)
            flag =false;
       // vis[r][c]=1;
        g1[r][c]=g2[r][c]=0;
        
        floodfill(g2,r-1,c,vis,g1);
        floodfill(g2,r,c-1,vis,g1);
        floodfill(g2,r+1,c,vis,g1);
        floodfill(g2,r,c+1,vis,g1);
        
    }
    
   /*   void floodfill2(vii &g2,int r,int c,vii &g1,int &count){
        if(r<0 || c<0 || r==g2.size() || c==g2[0].size() || g2[r][c]==0 )
            return ;
          
          if(g2[r][c] != g1[r][c]){
              count--;
              return;
          }
        
        g2[r][c]=0;
          g1[r][c]=0;
        
        floodfill2(g2,r-1,c,g1,count);
        floodfill2(g2,r,c-1,g1,count);
        floodfill2(g2,r+1,c,g1,count);
        floodfill2(g2,r,c+1,g1,count);
        
    }*/
    
    
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int m=g1.size();
        int n=g2[0].size();
        vii vis(m,vector<int>(n,0));
        int count=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g2[i][j]==1 && vis[i][j]==0){
                   flag = true;
                    floodfill(g2,i,j,vis,g1);
                if(flag==true)
                    count++;
               }
            }
        }
        /*int sum=count;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g2[i][j]==1 ){
                    floodfill2(g2,i,j,g1,sum);
                
               }
            }
        }*/
        
        return count;
        
    }
};