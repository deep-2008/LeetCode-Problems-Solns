class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        string result;
        int dp[n+1][m+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                result.push_back(str1[i-1]);
                j--;
                i--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    result.push_back(str2[j-1]);
                    j--;
                }
                else{
                    result.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        while(i>0){
            result.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            result.push_back(str2[j-1]);
            j--;
        }
        
        reverse(result.begin(),result.end());
        return result;
    }
};