class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size(),col=matrix[0].size(),maxi=INT_MIN;
        vector<vector<int>>dp(row, vector<int>(col)); //each cell will contain length of edge of max square possible by taking this cell as top right corner of the square
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                if(i==row-1 || j==col-1) dp[i][j]=matrix[i][j]-'0';         
                else{
                    if(matrix[i][j]=='0') dp[i][j]=0;
                    else{
                        dp[i][j]=min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]))+1;
                    
                    }
                }
                    maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi*maxi; //maxi is the length of edge of max square,we need area so we square it
    }
};