class Solution {
    int helper(vector<int>& s ,int k,int n,int c){
        if(n==1)
            return 1;
        
        int ans=0,sp=0,ep=0;
        
        while(ep<n){
            if(s[ep]!=c){
                if(k>0){
                    k--;
                }
                
                else{
                    
                    while(s[sp]==c)
                        sp++;
                    
                    sp++;
                }
            }
            ans=max(ans,ep-sp+1);
            ep++;
        }
        
        return ans;}
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
         return helper(nums,k,n,1);
    }
};