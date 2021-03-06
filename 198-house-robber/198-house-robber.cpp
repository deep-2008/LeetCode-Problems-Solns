class Solution {
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
        int t[n+1];
        if(n==1)
            return nums[0];
      t[0]=0;
        t[1]=nums[0];
        t[2]=max(nums[0],nums[1]);
        
        for(int i=2;i<n+1;i++){
            t[i] = max(t[i-1],t[i-2]+nums[i-1]);
        }
        return t[n];
    }
};