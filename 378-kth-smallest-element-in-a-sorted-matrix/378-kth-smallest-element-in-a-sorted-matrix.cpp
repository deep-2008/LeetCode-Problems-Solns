class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=0,h=n*n;
        
        priority_queue<int> maxh;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxh.push(matrix[i][j]); 
                
                if(maxh.size()>k)
                    maxh.pop();
                
            }
        }
        
        
        
        return maxh.top();
//         while(l<=h){
//             int mid=l+(h-l)/2;
            
//             if(mid==(k-1)){
//                 return matrix[mid/n][mid%n];
//             }
            
//             else if(mid<(k-1))
//                 l=mid;
            
//             else
//                 h=mid;
//         }
        
        // return -1;
    }
};