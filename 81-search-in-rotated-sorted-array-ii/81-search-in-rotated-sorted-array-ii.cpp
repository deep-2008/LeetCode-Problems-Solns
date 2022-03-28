class Solution {
public:
    bool search(vector<int>& nums, int target) {
      /*  sort(nums.begin(),nums.end());
        vector<int> ans;*/
        int n=nums.size(),count=0;
        
      /*  for(int i=0;i<n-1;i++){
            if(nums[i]<=nums[i+1])
                count++;
            else
                break;
        }
        
        for(int i=count+1;i<n;i++){
            ans.push_back(nums[i]);
        }
        
        for(int i=0;i<=count;i++){
            ans.push_back(nums[i]);
        }
        */
        int l=0,r=n-1;
        int mid=(l+r)/2;
        while(l<=r){
            if(nums[l]==target || nums[r]==target)
                return true;
            else{
                l++;r--;
            }
        }
        return false;
        
       /* while(l<r){
            if(nums[mid]==target)
                return true;
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        
        return false;*/
    }
};