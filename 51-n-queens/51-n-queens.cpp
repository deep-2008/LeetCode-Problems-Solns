#define vii vector<vector<string>>
#define vi vector<string>
class Solution {
public:
    bool valid(vi &board,int r,int c,int n){
       
        int row=r,col = c;
        
        while(r>=0 && c>=0){
            if(board[r][c]=='Q')
                return false;
            r--;c--;
        }
        
        r=row;c=col;
        
        while(c>=0){
            if(board[r][c]=='Q')
                return false;
            c--;
        }
        c=col;
        
        while(c>=0 && r<n){
            if(board[r][c]=='Q')
                return false;
            c--;r++;
        }
        
        return true;
    }
    
    
    void helper(vii &queen,vi &board,int n,int c){
        if(c==n){
            queen.push_back(board);
            return ;
        }
            
        
        for(int i=0;i<n;i++){
            
            
            if(valid(board,i,c,n))
            {
                board[i][c]='Q';
                helper(queen,board,n,c+1);
                board[i][c]='.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vii queen;
        vi board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
            board[i]=s;
        
        helper(queen,board,n,0);
        
        return queen;
    }
};