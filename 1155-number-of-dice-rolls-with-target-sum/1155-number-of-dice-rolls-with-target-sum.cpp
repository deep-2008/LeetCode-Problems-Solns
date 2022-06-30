#define mod 1000000007
int dp[50][1500];
class Solution {
    int solver(int ind,int n,int k,int target,int &sum,int &ans){
        if(ind==n+1){
            if(sum==target){
               return 1 ;
            }
            else
                return 0;
        }
        
        if(sum>target)
            return 0;
        
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        
        int result=0;
        
        for(int i=1;i<=k;i++){
            if(sum<target){
                sum+=i;
                result=(result+solver(ind+1,n,k,target,sum,ans)%mod)%mod;
                sum-=i;
            }
        }
        
        return dp[ind][sum]=result;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        int ans=0,sum=0;
        memset(dp,-1,sizeof(dp));
       return solver(1,n,k,target,sum,ans);
        
       // return ans;
    }
};