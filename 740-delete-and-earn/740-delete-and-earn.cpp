class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int temp[10001]={0};
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            
            temp[x]+=x;
        }
        
        int dp[10002];
        if(n==1)
            return nums[0];
        dp[0]=0;
        dp[1]=temp[0];
        
        for(int i=2;i<10002;i++){
            dp[i]=max(dp[i-1],dp[i-2]+temp[i-1]);
        }
        return dp[10001];
    }
};