class Solution {
    //#define mIn -10001;
public:
    int lengthOfLIS(vector<int>& nums) {
     /*   int n=nums.size(),omax=0;
        if(n==1)
            return 1;
        vector<int> dp(n,-1);
        //memset(dp,-1,sizeof(dp));
        dp[0]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    int c=dp[j]+1;
                    dp[i]= max(c,dp[i]);
                }
                
            }
            if(dp[i]==-1)
                dp[i]=1;
            if(dp[i]>omax)
                omax=dp[i];
        }
        //sort(dp.begin(),dp.end());
        
        return omax;*/
        
        int n=nums.size(),len=0;
        if(n==1)
            return 1;
        vector<int> help;
        help.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            if(nums[i]>help.back()){
                help.push_back(nums[i]);
                len++;
            }
            else{
               /* int j=0,k=help.size()-1;
               
                while(j<k){
                     int mid=(j+k)/2;
                if(help[mid]==nums[i])
                    help[mid]=nums[i];
                
                else if(help[mid] > nums[i])
                    k=mid-1;
                else
                    j=mid+1;*/
                int ind=lower_bound(help.begin(),help.end(),nums[i])- help.begin();
                help[ind]=nums[i];
                }
            }
        
        
        //int ans=help.size();
        return len+1;
    }
};