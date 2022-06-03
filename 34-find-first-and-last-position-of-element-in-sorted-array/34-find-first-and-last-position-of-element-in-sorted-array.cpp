class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int l=0,h=nums.size()-1,mid=0;
        
        // if(nums[l]==target && nums[h]==target)
        //     return {0,nums.size()-1};
        
        vector<int> ans;
        
        while(l<=h){
             mid=(l+h)/2;
            
            if(nums[mid] < target)
                l=mid+1;
            
            else if(nums[mid] > target)
                h=mid-1;
            
            else{
               int temp1=mid;
        
        while(mid!=0 && nums[mid-1]==target)
            mid=mid-1;
        
        ans.push_back(mid);
        
        mid=temp1;
        while(mid!=(nums.size()-1) && nums[mid+1]==target)
            mid=mid+1;
        
        ans.push_back(mid);
        return ans;
            }
        }
        
        
        
        return{-1,-1};
        
    }
};