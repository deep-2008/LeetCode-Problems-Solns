class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int op=0;
        
        for(int i=0;i<nums.size();i++){
            int r=k-nums[i];
            if(mp[r]>0){
                op++;
                mp[r]--;
            }
            else
                mp[nums[i]]++;
        }
        
       
        
        
        return op;
        
     /*   int l=0,r=nums.size()-1,count=0;
        sort(nums.begin(),nums.end());
        
        while(l<r && nums[l]<k){
            if(nums[l]+nums[r]>k)
                r--;
            else if(nums[l]+nums[r]<k)
                l++;
            else{
                l++;
                r--;
                count++;
            }
        }
        return count;*/
    }
};