class Solution {
    int dp[501][501][2];
    bool solve(vector<int>& piles,int i,int j,int f,int alice,int bob,int sum){
        if(i>=j)
            return alice>bob;
        
        if(alice>sum)
            return true;
        if(bob>sum)
            return false;
        
        if(dp[i][j][f]!=-1)
            return dp[i][j][f];
        
        int first=0,second=0;
        
        if(f==0){
            first=solve(piles,i+1,j,1,alice+piles[i],bob,sum) || solve(piles,i,j-1,1,alice+piles[j],bob,sum);
        }
        
        if(f==1){
            second=solve(piles,i+1,j,0,alice,bob+piles[i],sum) || solve(piles,i,j-1,0,alice,bob+piles[j],sum);
        }
        
        return dp[i][j][f]=first||second;
        // return first||second;
        
        
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size(),alice=0,bob=0;
        int sum=accumulate(piles.begin(),piles.end(),0);
        memset(dp,-1,sizeof(dp));
        
        // return solve(piles,0,n-1,0,alice,bob,sum/2);
        return true;
    }
};