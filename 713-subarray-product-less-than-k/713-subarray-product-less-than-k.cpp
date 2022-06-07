class Solution {
    
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        int mul=1;
        
        if(mul>=k)
            return 0;
        
        int i=0,j=0;
        
        while(j<n){
            mul=mul*nums[j];
            
            while(mul>=k){
                mul=mul/nums[i];
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
        
    }
};