class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        for(int i=0;i<m;i++){
            int k=i,j=0;
            vector<int> temp;
            while(k<m && j<n){
                temp.push_back(mat[k][j]);
                k++;j++;
            }
            sort(temp.begin(),temp.end());
            k=i,j=0;
            
             while(k<m && j<n){
                mat[k][j]=temp[j];
                k++;j++;
            }
        }
        
        
        for(int i=0;i<n;i++){
            int k=0,j=i;
            vector<int> temp;
            while(k<m && j<n){
                temp.push_back(mat[k][j]);
                k++;j++;
            }
            sort(temp.begin(),temp.end());
            k=0,j=i;
            
             while(k<m && j<n){
                mat[k][j]=temp[k];
                k++;j++;
            }
        }
        
        return mat;
    }
};