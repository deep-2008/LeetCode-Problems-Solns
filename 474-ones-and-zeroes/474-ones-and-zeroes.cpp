class Solution {
public:
    
    int dp[601][101][101];

int helper(vector<string> &v,int index,int m,int n)
{
    if(index >= v.size()) return 0;
    
    if(dp[index][m][n] != -1) return dp[index][m][n];
    
    int one = count(v[index].begin(),v[index].end(),'1');
    int zero = v[index].size() - one;
    
    if(m >= zero && n>= one){
        return dp[index][m][n] = max(1+helper(v,index+1,m-zero,n-one),helper(v,index+1,m,n));
    }
    else{
         return dp[index][m][n] =helper(v,index+1,m,n);
    }
}


int findMaxForm(vector<string>& v, int m, int n) {
    
    memset(dp,-1,sizeof(dp));
    
    return helper(v,0,m,n);
    
}
};