class Solution {
    int solve(vector<int>& nums,int k){
        int n=nums.size();
        // set<int> st;
        unordered_map<int,int> mp;
        int ans=0,sp=0,ep=0;
        
        while(ep<n){
            mp[nums[ep]]++;
            
            while(mp.size()>k){
                mp[nums[sp]]--;
                if(mp[nums[sp]]==0)
                    mp.erase(nums[sp]);
                sp++;
            }
            ans+=ep-sp+1;
            ep++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return solve(nums,k)-solve(nums,k-1);
                
    }
};