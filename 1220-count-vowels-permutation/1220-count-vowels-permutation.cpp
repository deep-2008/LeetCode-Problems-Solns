// a==1
// e==2
// i==3
// o==4
// u==5
   #define mod 1000000007
class Solution {
public:
    int solve(int Pre,int count,int &n,vector<vector<int>>&dp)
    {
        if(count==n)
            return 1;
        
        if(dp[count][Pre]!=-1) return dp[count][Pre]%mod;
        int ans=0;
        for(int i=1;i<=5;i++)
        {
            if(Pre==1 && i==2) 
                ans=(ans%mod+solve(i,count+1,n,dp)%mod)%mod;
            else if(Pre==2 && (i==1 || i==3)) 
                ans=(ans%mod+solve(i,count+1,n,dp)%mod)%mod;
            else if(Pre==3 && i!=3) 
                ans=(ans%mod+solve(i,count+1,n,dp)%mod)%mod;
            else if(Pre==4 && (i==3 || i==5)) 
                ans=(ans%mod+solve(i,count+1,n,dp)%mod)%mod;
            else if(Pre==5 && i==1) 
                ans=(ans%mod+solve(i,count+1,n,dp)%mod)%mod;
        }
        return dp[count][Pre]=ans%mod; 
    }
    int countVowelPermutation(int n) {
        
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(6,-1));
        for(int i=1;i<=5;i++)
        {
         ans= (ans%mod + solve(i,1,n,dp)%mod)%mod;
        }
        
        return ans%mod;
    }
};