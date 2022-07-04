class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if((mid>0 && nums[mid]==nums[mid-1]) || (mid<n-1) && nums[mid]==nums[mid+1]){
                if(mid>0 && nums[mid-1]==nums[mid]){
                    if((mid-1)%2==0)
                        l=mid+1;
                    else
                        h=mid-1;
                }
                else{
                    if(mid%2==0)
                        l=mid+1;
                    else
                        h=mid-1;
                }
            }
            else
            return nums[mid];
        }
        return 0;
    }
};