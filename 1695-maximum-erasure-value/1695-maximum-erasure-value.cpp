class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        long long int ans=0,sum=0;
        
        unordered_map<int,int> mp;
        int l=0,r=0;
        
        while(r<n){
            sum+=(1ll)*nums[r];
            mp[nums[r]]++;
            
            while(mp[nums[r]] > 1){
                mp[nums[l]]--;
                
                if(mp[nums[l]]==0)
                    mp.erase(nums[l]);
                
                sum-=(1ll)*nums[l];
                l++;
            }
            
            ans=max(ans,sum);
            r++;
        }
        
        return ans;
    }
};