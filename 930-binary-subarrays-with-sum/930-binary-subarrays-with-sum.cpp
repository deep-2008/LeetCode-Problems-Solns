class Solution {
    int solve(vector<int>& nums,int k){
        int n=nums.size();
        int sp=0,ep=0,ans=0;
        
        while(ep<n){
            if(nums[ep]==1){
                if(k>0)
                k--;
                
                else{
                     
                while(nums[sp]!=1)
                    sp++;
                sp++;
            }
        }   
            ans+=ep-sp+1;
            ep++;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // return 0;
        int a=solve(nums,goal);
        int b=0;
        if(goal>0)
            b=solve(nums,goal-1);
        
        return a-b;
    }
};