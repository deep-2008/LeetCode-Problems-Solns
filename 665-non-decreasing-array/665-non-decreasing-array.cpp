class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size(),count=0;
        
        for(int i=0;i<n-1;i++){
                            
            if(nums[i]>nums[i+1]){
                if(count==1)
                    return false;
                count++;
                
                if(i==0){
                    nums[i]=nums[i+1];
                }
                
                else{
                if(nums[i+1]>nums[i-1]){
                    nums[i]=nums[i+1];
                }
                
                else if(nums[i+1]==nums[i-1])
                    nums[i]=nums[i+1];
                
                else if(nums[i+1]<nums[i-1]){
                    nums[i+1]=nums[i];
                }
                }
            }
        }
        
        return true;
    }
};