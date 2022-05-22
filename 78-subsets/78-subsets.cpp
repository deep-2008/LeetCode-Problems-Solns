#define vii vector<vector<int>> 
#define vi vector<int>
class Solution {
public:
    void comb(vi &nums,vii &ans,vi &dp,int i ){
        if(i==nums.size()){
            ans.push_back(dp);
            return;
        }
        
        dp.push_back(nums[i]);
        comb(nums,ans,dp,i+1);
        
        dp.pop_back();
        comb(nums,ans,dp,i+1);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
       vii ans;
        vi dp;
        
        comb(nums,ans,dp,0);
        
        return ans;
    }
};