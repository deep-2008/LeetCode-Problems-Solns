class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
            int suffix=nums[0];
        int ans=nums[0];
        
        for(int i=1;i<nums.size();i++){
            suffix=max(nums[i],nums[i]+suffix);
            ans=max(ans,suffix);
        }
        return ans;
        
    }
};