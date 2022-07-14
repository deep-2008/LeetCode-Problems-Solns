class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0 || n==1)
            return n;
        
        vector<int> lesser(n,1),greater(n,1);
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]-nums[i+1]>0)
                greater[i]=lesser[i+1]+1;
            
            else if(nums[i]-nums[i+1]<0)
                lesser[i]=greater[i+1]+1;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,max(greater[i],lesser[i]));
        }
        
        return ans;
    }
};