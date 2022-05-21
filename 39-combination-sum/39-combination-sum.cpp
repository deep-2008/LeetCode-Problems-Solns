#define vii vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    void comb(vi &c,int target,vii &ans,vi &dp,int i){
        if(i==c.size()){
            if(target==0)
                ans.push_back(dp);
            return;
        }
        
       
        if(c[i]<=target){
             dp.push_back(c[i]);
            comb(c,target-c[i],ans,dp,i);
            dp.pop_back();
        }
        
        comb(c,target,ans,dp,i+1);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vii ans;
        vi dp;
        
        comb(candidates,target,ans,dp,0);
        
        return ans;
        
    }
};