#define vii vector<vector<int>> 
#define vi vector<int>
class Solution {
public:
    
    void comb(vi &nums,vii &ans,vi &dp,int ind){
      
            ans.push_back(dp);
           
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])
                continue;
            
            dp.push_back(nums[i]);
            comb(nums,ans,dp,i+1);
            dp.pop_back();
           
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vii ans;
        vi dp;
        sort(nums.begin(),nums.end());
        
        comb(nums,ans,dp,0);
        
        return ans;
    }
};