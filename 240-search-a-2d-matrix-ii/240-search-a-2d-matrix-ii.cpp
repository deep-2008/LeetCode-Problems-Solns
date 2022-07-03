class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int r=0,c=0;
        for(int i=0;i<m;i++){
            if(matrix[i][n-1]>=target){
                r=i;break;
            }
        }
        
//         for(int i=n-1;i>=0;i--){
//             if(matrix[r][i]<=target){
//                 c=i;break;
//             }
//         }
        
//         if(matrix[r][c]==target)
//             return true;
        
        
        for(int i=n-1;i>=0;i--){
        int l=r,h=m-1;
        
        while(l<=h){
            int mid=(l+h)/2;
            
            if(matrix[mid][i]==target)
                return true;
            
            else if(matrix[mid][i]<target)
                l=mid+1;
            else
                h=mid-1;
        }
        }
        
//         if(matrix[r][h]>target)
//             c=l;
        
//         else if(matrix[r][h]<target)
//             c=h;
        
//         int low=r,high=m-1;
        
//         while(low<=high){
//            int mid=(low+high)/2;
            
//             if(matrix[mid][c]==target)
//                 return true;
            
//             else if(matrix[mid][c]<target)
//                 l=mid+1;
//             else
//                 h=mid-1;
//         }
        
        return false;
    }
};