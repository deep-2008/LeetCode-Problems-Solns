class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1||nums[0]==0)
            return 0;
        int farthest=0,current=0,jumps=0;
        
        for(int i=0;i<nums.size()-1;i++){
            farthest=max(farthest,nums[i]+i);
            
            if(i==current){
                current=farthest;
                jumps++;
            }
            
        }
        return jumps;
    }
};