// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code long 
        long long int sum=0;
        
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum%2==1)
        return 0;
        
        int s1=sum/2;
        vector<vector<int>> dp(N+1,vector<int> (s1+1,-1));
        
        for(int i=0;i<N+1;i++){
            for(int j=0;j<s1+1;j++){
                if(i==0)
                dp[i][j]=0;
                
                else if(j==0)
                dp[i][j]=1;
                
                else if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[N][s1];
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends