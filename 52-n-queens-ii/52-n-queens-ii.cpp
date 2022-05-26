#define vii vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    bool valid(vii &queen,int n,int row,int col){
        int r=row,c=col;
        
        while(r>=0 && c>=0){
            if(queen[r][c]==1)
                return false;
            r--;c--;
        }
        
        r=row;c=col;
        
        while(c>=0){
            if(queen[r][c]==1)
                return false;
            c--;
        }
        c=col;
        
        while(r<n && c>=0){
            if(queen[r][c]==1)
                return false;
            c--;r++;
        }
        
        return true;
    }
    
    
    void helper(vii &queen,int n,int &count,int col){
        if(col==n){
            count++;
            return;
        }
        
        for(int i=0;i<n;i++){
            if(valid(queen,n,i,col)){
                queen[i][col]=1;
                helper(queen,n,count,col+1);
                queen[i][col]=0;
            }
        }
    }
    
    
    int totalNQueens(int n) {
        vii queen(n,vi (n,0));
        
        int count=0;
        
        helper(queen,n,count,0);
        
        return count;
    }
};