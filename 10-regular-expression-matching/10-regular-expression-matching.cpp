class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }else if(i==0){
                    dp[i][j]=0;
                }else if(j==0){
                    char c=p[i-1];
                    if(c=='*'){
                        dp[i][j]=dp[i-2][j];
                    }
                    
                    else{
                        dp[i][j]=0;
                    }
                }else{
                    char pc=p[i-1];
                    char sc=s[j-1];
                    
                    if(pc=='*'){
                        dp[i][j]=dp[i-2][j];
                        
                        char plc=p[i-2];
                        if(plc=='.' || plc==sc){
                            dp[i][j]=dp[i][j] || dp[i][j-1];
                        }
                    }else if(pc=='.'){
                        dp[i][j]=dp[i-1][j-1];
                    }else if(pc==sc){
                        dp[i][j]=dp[i-1][j-1];
                    }else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};