class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        
        vector<int> pref(n);
        unordered_map<int,int> mp;
        
        pref[0]=nums[0];
        
        for(int i=1;i<n;i++){
            pref[i] = nums[i]+pref[i-1];
        }
        
        for(int i=0;i<n;i++){
            if(pref[i]==k)
                ans++;
            
            if(mp.find(pref[i] - k) != mp.end())
                ans+=mp[pref[i]-k];
            
            mp[pref[i]]++;
        }  
        
    
        
        return ans;
    }
};