// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string X, string Y) 
	{ 
	    // Your code goes here
	    int m=X.size();
	    int n=Y.size();
	    int result = n+m;
        int dp[m+1][n+1];
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0)
                dp[i][j]=0;
                
                else if(X[i-1]==Y[j-1])
                dp[i][j]= 1+dp[i-1][j-1];
                
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        if(dp[m][n] == n)
        return m-dp[m][n];
        
        else 
        return (result - (2*dp[m][n]));
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends