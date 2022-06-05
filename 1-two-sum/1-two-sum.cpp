class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
       unordered_map<int,int> mp;
        
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]=i;
        // }
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end())
                return {i,mp[target-nums[i]]};
            
            mp[nums[i]]=i;
        }
        return result;
    }
};