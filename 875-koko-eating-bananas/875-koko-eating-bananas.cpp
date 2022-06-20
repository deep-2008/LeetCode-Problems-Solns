class Solution {
    int isPossible(vector<int>& nums,int mid,int h){
       int sum=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] % mid==0){
                sum+= (nums[i]/mid);
            }
            else
                sum+= (nums[i]/mid)+1;
            
            if(sum>h)
                return 0;
        }
        return 1;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int k) {
      int l=999999999,h=-1,n=piles.size();
        int ans=0;
        
        for(auto i:piles){
            l=min(l,i);
            h=max(h,i);
        }
        l=1;
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(isPossible(piles,mid,k)){
                ans=mid;
                h=mid-1;
            }
            
            else
                l=mid+1;
        }
        
        return ans;
    }
};