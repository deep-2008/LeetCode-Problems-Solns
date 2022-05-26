class Solution {
public:
    bool valid(vector<vector<char>>& board,int r,int col,char c){
        
        for(int i=0;i<9;i++){
            if(board[i][col] == c)
                return false;
            
            if(board[r][i]==c)
                return false;
            
            if(board[3*(r/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        
        return true;
    }
    
    
    bool helper(vector<vector<char>>& board,int n){
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               
               if(board[i][j]=='.'){
                   for(char c='1';c<='9';c++){
                       if(valid(board,i,j,c)){
                           board[i][j]= c;
                       
                       if(helper(board,n)==true)
                           return true;
                       else
                           board[i][j]='.';
                   }
                   }
                   return false;
               }
               
           }
       }
        
        return true;
       
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        
        helper(board,n);
    }
};