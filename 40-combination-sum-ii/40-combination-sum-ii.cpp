/*#define vii vector<vector<int>> 
#define vi vector<int>
class Solution {
public:
    void comb(vi &c,int target,set<vi> &ans,vi &dp,int i){
        if(i==c.size()){
            if(target==0)
                ans.insert(dp);
            return;
        }
        
        if(c[i]<=target){
            dp.push_back(c[i]);
            comb(c,target-c[i],ans,dp,i+1);
            dp.pop_back();
        }
        
        comb(c,target,ans,dp,i+1);
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     set<vi> ans;
        vi dp;
        sort(candidates.begin(),candidates.end());
        
        comb(candidates,target,ans,dp,0);
        
        vii res;
        
        for(auto it= ans.begin();it!=ans.end();it++){
            res.push_back(*it);
        }
        
        return res;
    }
};*/


#define vii vector<vector<int>> 
#define vi vector<int>
class Solution {
public:
    void comb(vi &c,int target,vii &ans,vi &dp,int ind){
        if(target==0){
            ans.push_back(dp);
            return;
        }
        
        for(int i=ind;i<c.size();i++){
            if(i>ind && c[i]==c[i-1])
                continue;
            
            if(c[i]>target)
                break;
            
            dp.push_back(c[i]);
            comb(c,target-c[i],ans,dp,i+1);
            dp.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vii ans;
        vi dp;
        sort(candidates.begin(),candidates.end());
        
        comb(candidates,target,ans,dp,0);
        
        return ans;
    }
};