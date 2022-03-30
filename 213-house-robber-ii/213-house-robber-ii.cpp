class Solution {
public:
    /*void inserT(vector<int> &nums,vector<int> &v,int i,int n){
        while(i<=n){
            v.push_back(nums[i]);
        i++;}
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
       vector<int> v1,v2;
        
        inserT(nums,v1,0,n-2);
        inserT(nums,v2,1,n-1);
        int x=v1.size();
        int dp1[x+1];
        dp1[0]=0;
        dp1[1]=v1[0];
        dp1[2]=max(dp1[1],v1[1]);
        for(int i=3;i<x+1;i++){
            dp1[i]=max(dp1[i-1],dp1[i-2]+v1[i-1]);
        }
        
        int y=v2.size();
        int dp2[y+1];
        dp2[0]=0;
        dp2[1]=v1[0];
        dp2[2]=max(dp2[1],v2[1]);
        for(int i=3;i<y+1;i++){
            dp2[i]=max(dp2[i-1],dp2[i-2]+v2[i-1]);
        }
        if(dp1[x]>=dp2[y])
            return dp1[x];
        return dp2[y];
    }*/
    
     int rec(vector<int> &nums, int n, int dp[], int x)
    {
        if(n <= 1-x) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = max(nums[n-1] + rec(nums, n-2, dp, x), rec(nums, n-1, dp, x));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
		//from N to 1
        int op1 = rec(nums, n, dp, 0);
		
        memset(dp, -1, sizeof(dp));
		//from N-1 to 0
        int op2 = rec(nums, n-1, dp, 1);
        
		//max of both the parts
        return max(op1, op2);
    }
};