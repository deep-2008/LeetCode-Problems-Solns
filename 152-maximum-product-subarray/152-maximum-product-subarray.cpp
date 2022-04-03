class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int csum=nums[0],osum=nums[0];
        
        for(int i=1;i<n;i++){
           /* if(csum>0){
                if(nums[i]>0)
                    csum*=nums[i];
                else if(nums[i]<0)
                    csum=nums[i];
                else
                    csum=0;
            }
            else if(csum<0){
                if(nums[i]>0)
                    csum=nums[i];
                else if(nums[i]<0)
                    csum*=nums[i];
                else
                    csum=0;
            }
            
            else{
                if(nums[i]>0)
                    csum=nums[i];
                else if(nums[i]<0)
                    csum=nums[i];
                else
                    csum=0;
            }*/
            if(csum==0)
                csum=1;
            csum*=nums[i];
            osum=max(osum,csum);
        }
        csum=0;
        for(int i=n-1;i>=0;i--){
            if(csum==0)
                csum=1;
            csum*=nums[i];
            osum=max(osum,csum);
        }
        return osum;
    }
};