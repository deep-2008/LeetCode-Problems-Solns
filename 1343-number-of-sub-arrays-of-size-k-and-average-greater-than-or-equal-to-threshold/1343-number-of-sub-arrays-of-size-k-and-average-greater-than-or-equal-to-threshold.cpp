class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n=nums.size();
        int sp=0,ep=0,avg=0,ans=0;
        
        for(int i=0;i<k;i++)
            avg+=nums[i];
        
        if(avg/k>=threshold)
            ans++;
        
        for(int i=k;i<n;i++){
            avg+=nums[i];
            avg-=nums[sp];
            
            if(avg/k>=threshold)
                ans++;
            sp++;
        }
        
        
        return ans;
    }
};