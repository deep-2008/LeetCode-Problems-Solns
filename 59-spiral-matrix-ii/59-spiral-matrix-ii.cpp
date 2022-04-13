class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         int m=n*n,cnt=1;
        vector<vector<int>> opt(n,vector<int> (n));
        
       //i=layer
        for(int i=0;i<(n+1)/2;i++){
            for(int ptr=i;ptr<n-i;ptr++){
                opt[i][ptr]=cnt;
                cnt++;
            }
            
            for(int ptr=i+1;ptr<n-i;ptr++){
                opt[ptr][n-i-1]=cnt;
                cnt++;
            }
            
            for(int ptr=n-i-2;ptr>=i;ptr--){
                opt[n-i-1][ptr]=cnt;
                cnt++;
            }
            
            for(int ptr=n-i-2;ptr>i;ptr--){
                opt[ptr][i]=cnt;
                cnt++;
            }
        }
        
        return opt;
    }
};