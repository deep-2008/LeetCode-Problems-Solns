class Solution {
    int dp[10001];
   long long int minJumps(vector<int>& nums,int ind,int &Jump,int n){
        if(ind==n-1)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
       long long int temp=INT_MAX;
        
        int maxJump=nums[ind];
        
        for(int i=1;i<=maxJump;i++){
            // Jump++;
            if(ind+i>=n)
                break;
            
            temp=min(temp,(1ll)*1+minJumps(nums,ind+i,Jump,n));
            // Jump--;
        }
        
       dp[ind]=temp;
        return temp;
    }
public:
    int jump(vector<int>& nums) {
      memset(dp,-1,sizeof(dp));
        int Jump=0;
        return minJumps(nums,0,Jump,nums.size());
    }
};











































// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         if(nums.size()==1||nums[0]==0)
//             return 0;
//         int farthest=0,current=0,jumps=0;
        
//         for(int i=0;i<nums.size()-1;i++){
//             farthest=max(farthest,nums[i]+i);
            
//             if(i==current){
//                 current=farthest;
//                 jumps++;
//             }
            
//         }
//         return jumps;
//     }
// };