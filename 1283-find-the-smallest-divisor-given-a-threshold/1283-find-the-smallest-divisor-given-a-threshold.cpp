class Solution {
    
    int isPossible(vector<int>& nums,int th,int mid){
       long long int sum=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] % mid==0){
                sum+=nums[i]/mid;
            }
            
            else
                sum+= (nums[i]/mid)+1;
            
            if(sum>th)
                return 0;
        }
        
        return 1;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
      long long int n=nums.size();
        
       long long int sum=0;
        for(auto i:nums)
            sum+=i;
        
       long long int l=1,h=sum;
         int ans=INT_MAX;
        
        while(l<=h){
            long long int mid=l+(h-l)/2;
            
            if(isPossible(nums,threshold,mid)==1){
                ans=min(mid,(1ll)*ans);
                h=mid-1;
            }
            
            else
                l=mid+1;
        }
        
        return ans;
    }
};