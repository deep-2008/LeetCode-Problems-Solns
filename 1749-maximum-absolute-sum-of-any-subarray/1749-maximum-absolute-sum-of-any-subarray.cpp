class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
      int csum=0,osum=0,csum1=0,osum1=0;
        
        for(int i=0;i<nums.size();i++){
           if(csum>=0)
               csum+=nums[i];
            else
            csum=nums[i];
            
            osum=max(osum,csum);
        }
        
        for(int i=0;i<nums.size();i++){
           if(csum1<=0)
               csum1+=nums[i];
            else
            csum1=nums[i];
            
            osum1=min(osum1,csum1);
        }
        return max(osum,abs(osum1));
    }
};