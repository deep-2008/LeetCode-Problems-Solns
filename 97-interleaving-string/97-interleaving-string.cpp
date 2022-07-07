class Solution {
//     bool checkSequence(string s1,string s2,string s3,int i,int j,vector<vector<int>> dp){
//         if(i==s1.size() && j==s2.size())
//             return true;
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         if(i<s1.size() && s1[i]==s3[i+j]){
//             bool f1=checkSequence(s1,s2,s3,i+1,j,dp);
//             dp[i][j]=f1;
            
//             if(f1==true)
//             return true;
//         }
        
//         if(j<s2.size() && s2[j]==s3[i+j]){
//             bool f2=checkSequence(s1,s2,s3,i,j+1,dp);
//             dp[i][j]=f2;
            
//             if(f2==true)
//                 return true;
//         }
        
//         dp[i][j]=false;
//         return false;
//     }
public:
//     bool isInterleave(string s1, string s2, string s3) {
//         int n=s1.size();
//         int m=s2.size();
        
//         if(n+m!=s3.size())
//             return false;
        
//         vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
//         return checkSequence(s1,s2,s3,0,0,dp);
//     }
    
    
     bool isInterleave(string s1, string s2, string s3) {
    
    if(s3.length() != s1.length() + s2.length())
        return false;
    
    bool table[s1.length()+1][s2.length()+1];
    
    for(int i=0; i<s1.length()+1; i++)
        for(int j=0; j< s2.length()+1; j++){
            if(i==0 && j==0)
                table[i][j] = true;
            else if(i == 0)
                table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
            else if(j == 0)
                table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
            else
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
        }
        
    return table[s1.length()][s2.length()];
}
};