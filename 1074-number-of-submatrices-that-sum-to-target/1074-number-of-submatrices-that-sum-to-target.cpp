class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),count=0;
        vector<vector<int>> pref(n+1,vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pref[i+1][j]=pref[i][j]+matrix[i][j];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=0;k<m;k++){
                    int sum=0;
                    for(int l=k;l<m;l++){
                        sum+=pref[j][l]-pref[i][l];
                        if(sum==target)
                            count++;
                    }
                }
            }
        }
        return count;
    }
};
