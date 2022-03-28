// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isPalindrom(string str,int i,int j){
    while(i<=j){
        if(str[i]==str[j]){
            i++;j--;
        }
        else
        return 0;
    }
    return 1;
}

int solve(string str,int dp[][501],int i,int j){
    if(i>=j)
    return 0;
    
    if(isPalindrom(str,i,j)==1)
    return 0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    int left,right;
    
    int mn=INT_MAX;
    
    for(int k=i;k<=j-1;k++){
        if(dp[i][k] != -1)
         left=dp[i][k];
        else
        left =solve(str,dp,i,k);
        
        if(dp[k+1][j]!=-1)
         right=dp[k+1][j];
        else
         right=solve(str,dp,k+1,j);
        
        int temp=left + 1 + right;
       
        
        if(temp<mn)
        mn=temp;
    }
    
    return dp[i][j]=mn;
}
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        int dp[501][501];
        memset(dp,-1,sizeof(dp));
        
        return solve(str,dp,0,n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends