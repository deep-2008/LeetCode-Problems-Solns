class Solution {
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
        int t[n];
        if(n==1)
            return nums[0];
      t[0]=nums[0];
        t[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            t[i] = max(t[i-1],t[i-2]+nums[i]);
        }
        return t[n-1];
    }
};