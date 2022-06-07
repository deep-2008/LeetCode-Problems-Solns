class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),sum=0,ans=INT_MAX;
        int j=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            while(sum >= target){
                ans=min(ans,i-j+1);
                sum-=nums[j];
                j++;
            }
        }
        
        if(sum<=target && j==0)
            return 0;
        
        return ans;
    }
};