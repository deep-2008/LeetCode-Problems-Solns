class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n=nums.size(),ans=0;
        
        for(int i=0;i<n-1;i++){
            int a=nums[i];
            for(int j=i+1;j<n;j++){
              a^= nums[j];
                
                if(a==0)
                    ans+=(j-i);
            }
        }
        return ans;
    }
};