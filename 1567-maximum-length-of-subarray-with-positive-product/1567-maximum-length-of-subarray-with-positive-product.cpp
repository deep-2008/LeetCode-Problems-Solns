class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int count=0,ans=0,n=nums.size(),mod=1e9+7;
        long long int csum=0;
        
        if(n==1 && nums[0]>0)
            return 1;
        
        for(int i=0;i<n;i++){
            if(csum==0 || nums[i]==0){
                csum=1;
                count=0;
               // continue;
            }
            
            csum=(csum*nums[i])%mod;
            count++;
            if(csum>0)
            ans=max(ans,count);        
        }
        csum=0,count=0;
        for(int i=n-1;i>=0;i--){
            if(csum==0 || nums[i]==0){
                csum=1;
                count=0;
            }
            
            csum= (csum*nums[i])%mod;
            count++;
            
            if(csum>0)
                ans=max(ans,count);
        }
        
        
            return ans;
      
    }
};