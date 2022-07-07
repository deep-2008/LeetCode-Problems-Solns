class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
//         vector<int> dp(n,-1);
        
//         if(n<3)
//             return false;
        
//         dp[0]=1;
        
//         for(int i=1;i<n;i++){
//             for(int j=0;j<i;j++){
                
//                 if(nums[j]<nums[i]){
//                 int c=dp[j]+1;
//                 dp[i]=max(dp[i],c);
                    
//                     if(dp[i]>=3)
//                 return true;
//                 }
//             }
//             if(dp[i]==-1)
//                 dp[i]=1;
            
            
            
//         }
        
        int l=INT_MAX,h=INT_MAX;
        
        for(auto x:nums){
            if(x<=l)
                l=x;
            
            else if(x<=h)
                h=x;
            
            else 
                return true;
        }
        return false;
    }
};