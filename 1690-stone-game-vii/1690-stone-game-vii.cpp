class Solution {
    int dp[1001][1001][2];
    int solve(vector<int>& stones,int sum,int l,int h,int turn){
        if(l>=h || sum<0)
            return 0;
        
        if(dp[l][h][turn]!=0)
            return dp[l][h][turn];
        
        int a=0,b=0,diff=0;
        
        //int front=sum-stones[l]-solve(stones,sum-stones[l],l+1,h,0);
        //int back=sum-stones[h]-solve(stones,sum-stones[h],l,h-1,1);
        
        if(turn ==1){
            a=max(sum-stones[l]-solve(stones,sum-stones[l],l+1,h,0),sum-stones[h]-solve(stones,sum-stones[h],l,h-1,0));
        }
        
        else{
            b=max(sum-stones[l]-solve(stones,sum-stones[l],l+1,h,1),sum-stones[h]-solve(stones,sum-stones[h],l,h-1,1));
        }
        // diff=max(front,back);
        diff=max(a,b);
        return dp[l][h][turn]=diff;
    }
    
public:
    int stoneGameVII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        memset(dp,0,sizeof(dp));
        
        return solve(stones,sum,0,stones.size()-1,1);
    }
};