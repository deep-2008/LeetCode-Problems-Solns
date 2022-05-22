#define vii vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    void comb(vi &nums,vii &ans,vi &ds,int &k,int target,int ind){
        if( ds.size()==k){
            if(target==0){
                ans.push_back(ds);
            return;
            }
        }
        
        for(int i=ind;i<nums.size();i++){
            if(nums[i]>target)
                break;
            
            ds.push_back(nums[i]);
            comb(nums,ans,ds,k,target-nums[i],i+1);
            ds.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vii ans;
        vi nums;
        vi ds;
        if(k>n)
            return ans;
        
        for(int i=0;i<9;i++){
            nums.push_back(i+1);
        }
        
        comb(nums,ans,ds,k,n,0);
        
        return ans;
        
    }
};