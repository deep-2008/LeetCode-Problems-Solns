class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        
        
        
        vector<pair<int,int>> live;
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                if(i-1>=0){
                    for(int a=j-1;a<=j+1;a++ ){
                        if(a>=0 && a<n && board[i-1][a]==1)
                            count++;
                    }
                }
                
                for(int a=j-1;a<=j+1;a+=2){
                    if(a>=0 && a<n && board[i][a]==1)
                        count++;
                }
                
                if(i+1<m){
                    for(int a=j-1;a<=j+1;a++){
                        if(a>=0 && a<n && board[i+1][a]==1)
                            count++;
                    }
                }
                
                if(board[i][j]==0 && count==3)
                    live.push_back({i,j});
                
                else if(board[i][j]==1 && (count<2 || count>3))
                    live.push_back({i,j});
            }
        }
        
       for(int i=0;i<live.size();i++){
           if(board[live[i].first][live[i].second]==1)
               board[live[i].first][live[i].second]=0;
           else
               board[live[i].first][live[i].second]=1;
       }
        
        
    }
};