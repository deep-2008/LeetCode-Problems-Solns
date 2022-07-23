class Solution {
    int dp[100001][2][3];
//     int solve(vector<int>& prices,int n,int ind,int buy,int count,int &ans){
//         if(ind==n || count==2)
//             return 0;
        
//         if(dp[ind][buy][count]!=0)
//             return dp[ind][buy][count];
        
//         int profit=0;
//         if(buy==1){
//             profit=max(-prices[ind]+solve(prices,n,ind+1,0,count,ans),solve(prices,n,ind+1,1,count,ans));
//         }
        
//         else{
//             profit=max(prices[ind]+solve(prices,n,ind+1,1,count+1,ans),solve(prices,n,ind+1,0,count,ans));
//         }
        
//         // ans=max(ans,profit);
//         // cout<<profit<<" ";
//         return dp[ind][buy][count]=profit;
//     }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),ans=0,count=0;
        memset(dp,0,sizeof(dp));
        
        // return solve(prices,n,0,1,0,ans);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int count=0;count<2;count++){
                         int profit=0;
        if(buy==1){
            profit=max(-prices[ind]+dp[ind+1][0][count],dp[ind+1][1][count]);
        }
        
        else{
            profit=max(prices[ind]+dp[ind+1][1][count+1],dp[ind+1][0][count]);
        }
    
         dp[ind][buy][count]=profit;
                }
            }
        }
        
        // return ans;
        
        // cout<<dp[0][0][0]<<" "<<dp[0][0][1]<<" "<<dp[0][0][2]<<" "<<dp[0][1][0]<<" "<<dp[0][1][1]<<" "<<dp[0][1][2]<<" "<<dp[1][0][0]<<" "<<dp[1][0][1]<<" "<<dp[1][0][2]<<" "<<dp[1][1][0]<<" "<<dp[1][1][1]<<" "<<dp[1][1][2]<<endl<<endl;
        
        return dp[0][1][0];
    }
};