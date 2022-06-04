class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][n-1]<target)
                    j=j+n;
                else if(matrix[i][n-1]==target)
                    return true;
                else{
                    int l=0;
                    int r=n-1;
                   
                    while(l<=r){
                         int mid=(l+r)/2;
                        if(matrix[i][mid]==target)
                            return true;
                        else if(matrix[i][mid]>target)
                            r=mid-1;
                        else
                            l=mid+1;
                    }
                }
                //j=j+n;
            }
        }
        return false;
    }
};