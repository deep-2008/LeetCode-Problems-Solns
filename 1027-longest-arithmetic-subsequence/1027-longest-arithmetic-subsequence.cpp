class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),res=0;
        
        vector<unordered_map<int,int>> dp(n);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int cd=nums[i]-nums[j];
                dp[i][cd]=dp[j].count(cd)>0?dp[j][cd]+1:2;
                
                res=max(res,dp[i][cd]);
            }
        }
        
        return res;
    }
};