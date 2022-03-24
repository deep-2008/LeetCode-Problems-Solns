// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        //int m=price.size();
        vector<int> length;
        
        for(int i=0;i<n;i++){
          length.push_back(i+1);
       }
        
      //  int dp[n+1][length.size()+1];
      int dp[n+1][n+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0)
                dp[i][j]=0;
                
                else if(j==0)
                dp[i][j]=0;
                
                else{
                    if(length[i-1]<=j)
                    dp[i][j] = max(dp[i-1][j] , price[i-1]+dp[i][j-length[i-1]]);
                    
                    else
                    dp[i][j]=dp[i-1][j];
                }
            }}
            return dp[n][n];
            /* int length[n], i, j;
       int t[n+1][n+1];
       
       for( i=0; i<n; i++)
           length[i] =i+1;
           
       for(i=0; i<n+1; i++)
       for(j=0; j<n+1; j++)
           if( i==0 || j==0)
               t[i][j]= 0;
               
       for(i=1; i<n+1; i++)
       for(j=1; j<n+1; j++)
       {
           if(length[i-1] <= j)
               t[i][j] = max(price[i-1]+t[i][j-length[i-1]], t[i-1][j]);
           
           else
               t[i][j] = t[i-1][j];
       }
       return t[n][n];*/
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends