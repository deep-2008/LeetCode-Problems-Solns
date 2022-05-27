class Solution {
public:
    
    bool valid(vector<vector<int>>& matrix,int row,int col,int x,int n){
        for(int i=0;i<n;i++){
            if(i!=row && matrix[i][col]==x)
                return false;
            
            if(i!=col && matrix[row][i]==x)
                return false;
        }
        
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x= matrix[i][j];
                
                if(!valid(matrix,i,j,x,n))
                    return false;
            }
        }
        
        return true;
    }
};