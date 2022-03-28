class Solution {
public:
    int solve(vector<int>& arr,int dp[][101],int i,int j){
    if(i>=j)
    return 0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int mn = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = solve(arr,dp,i,k)+solve(arr,dp,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(temp<mn)
        mn=temp;
    }
    return dp[i][j]=mn;
}
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        int static dp[101][101];
        memset(dp,-1,sizeof(dp));
        return solve(values,dp,1,n-1);
    }
};