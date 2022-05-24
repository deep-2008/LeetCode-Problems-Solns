#define vii vector<vector<int>> 
#define vi vector<int>
/*class Solution {
public:
    void helper(vi &nums,vii &ans,vi &vis,vi &ds,int ind){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                ds.push_back(nums[i]);
                helper(nums,ans,vis,ds,i+1);
                vis[i]=0;
                 ds.pop_back();
            }
           
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
       vii ans;
        vi vis(nums.size(),0);
        vi ds;
        
        helper(nums,ans,vis,ds,0);
        
        return ans;
    }
};*/

//OPTIMISED
class Solution {
public:
    void helper(vi &nums,vii &ans,int ind){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            helper(nums,ans,ind+1);
            swap(nums[i],nums[ind]);
           
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
       vii ans;
       // vi vis(nums.size(),0);
     //   vi ds;
        
        helper(nums,ans,0);
        
        return ans;
    }
};