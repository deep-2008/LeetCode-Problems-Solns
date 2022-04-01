class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return true;
        if(nums[0]==0)
            return false;
        int reachable=0;
        
        for(int i=0;i<n;i++){
            if(i>reachable)
                return false;
            reachable=max(reachable,nums[i]+i);
        }
        return true;
        
        
    }
};