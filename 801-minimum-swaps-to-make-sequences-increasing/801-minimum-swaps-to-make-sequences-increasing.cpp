class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        
        // vector<int> swap(n,0);
        // vector<int> no_swap(n,0);
        // swap[0]=1;
        // no_swap[0]=0;
        
        vector<int> prev={0,1};
        
        if(n==1)
            return 0;
        
        for(int i=1;i<n;i++){
            vector<int> curr={INT_MAX,INT_MAX};
            
            if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]){
                curr[0]=prev[0];
                curr[1]=prev[1]+1;
            }
            
           if(nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]){
               curr[1]=min(prev[0]+1,curr[1]);
               curr[0]=min(prev[1],curr[0]);
           }
            
            prev[0]=curr[0];
            prev[1]=curr[1];
        }
        
        return min(prev[0],prev[1]);
    }
};