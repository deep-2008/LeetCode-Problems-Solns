// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {

        // code here.
       /* long long int dp[n+1];
        sort(S,S+m);
        dp[0]=1;
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<m;j++){
                if(S[i]<=j)
                dp[i]= dp[i]+dp[j-S[i]];
            }
        }
        return dp[n];*/
        
        long long int dp[m+1][n+1];
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0)
                dp[i][j]=0;
                
               else if(j==0)
                dp[i][j]=1;
                
                else{
                if(S[i-1]<=j)
                dp[i][j]=dp[i-1][j]+ dp[i][j-S[i-1]];
                
                else
                dp[i][j]=dp[i-1][j];
            }}
        }
        
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends