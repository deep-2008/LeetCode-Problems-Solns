class Solution {
public:
    bool valid(vector<vector<char>>& board,int row,int col,char c1){
        for(int i=0;i<9;i++){
            if(i!=row && board[i][col]==c1)
                return false;
            
            if(i!=col && board[row][i]==c1)
                return false;
            
            
        }
        
        int r=row%3;
        int c=col%3;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==r && j==c)
                    continue;
                
                if(board[3*(row/3)+i][3*(col/3)+j]==c1)
                    return false;
            }
        }
        return true;
    }
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] !='.'){
                    char c = board[i][j];
                    if(valid(board,i,j,c)==false)
                        return false;
                }
            }
        }
        
        return true;
    }
};