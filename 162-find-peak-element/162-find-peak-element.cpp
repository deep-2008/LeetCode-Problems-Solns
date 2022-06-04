class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        
        int l=0,h=nums.size()-1;
        
        while(l<=h){
            if(nums[l+1] < nums[l])
                return l;
            
            if(nums[h-1] > nums[h]){
                if(nums[h-1]>nums[h-2])
                    return h-1;
            }
               
            
            l++;
            h--;
        }
        
        return nums.size()-1;
    }
};