#define vii vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    void helper(vi &nums,vii &ans,vi &vis,vi &ds,int n,int k,int ind){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
            
            for(int i=ind;i<n;i++){
                if(!vis[i]){
                    vis[i]=1;
                    ds.push_back(nums[i]);
                    helper(nums,ans,vis,ds,n,k,i+1);
                    vis[i]=0;
                    ds.pop_back();
                }
            }
    }
    vector<vector<int>> combine(int n, int k) {
     // set<vi> ans;
        vi nums,ds;
        vi vis(n,0);
        vii ans;
        
        for(int i=0;i<n;i++)
            nums.push_back(i+1);
        
        helper(nums,ans,vis,ds,n,k,0);
        
       
        return ans;
    }
};