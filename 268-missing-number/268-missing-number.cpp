class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*int maxm=0;
        
        for(int i=0;i<nums.size();i++)
            maxm=max(maxm,nums[i]);
        
        vector<int> vis(maxm+1,0);
        
        for(int i=0;i<nums.size();i++){
            vis[nums[i]]=1;
        }
        
        for(int i=0;i<maxm+1;i++){
            if(!vis[i]){
                return i;
            }
        }
        
        return maxm+1;*/
        
        int sum=0;
        int n=nums.size();
        int total=(n*(n+1))/2;
        
        for(int num: nums)
            sum+=num;
        
        return total-sum;
    }
};