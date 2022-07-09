class Solution {
    int dp[10001];
    
    bool helper(vector<int> &nums,int ind,int n){
        if(ind==n-1)
            return true;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int maxJump=nums[ind];
        
        for(int i=1;i<=maxJump;i++){
            if(helper(nums,ind+i,n))
                return dp[ind]=true;
        }
        
        return dp[ind]=false;
    }
public:
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        
        return helper(nums,0,nums.size());
    }
};









































// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1)
//             return true;
//         if(nums[0]==0)
//             return false;
//         int reachable=0;
        
//         for(int i=0;i<n;i++){
//             if(i>reachable)
//                 return false;
//             reachable=max(reachable,nums[i]+i);
//         }
//         return true;
        
        
//     }
// };