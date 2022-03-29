class Solution {
public:
    
    int findDuplicate(vector<int>& nums) {
        
        int l=1,r=nums.size()-1,count=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            count=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=mid)
                    count++;
            }
            if(count<=mid)
                l=mid+1;
            else
                r=mid-1;
        }
        return l;
    }
};