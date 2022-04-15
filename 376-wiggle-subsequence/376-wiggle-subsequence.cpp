/*class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        if(nums.size()==2 && nums[0] !=nums[1])
            return 2;
     vector<int> temp;
        for(int i=1;i<nums.size();i++)
            temp.push_back(nums[i]-nums[i-1]);
        
        int n=temp.size(),omax=0,cnt=0;
        
        
        int dp[n];
        memset(dp,-1,sizeof(dp));
        dp[0]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(temp[i]>0){
                    if(temp[j]<0){
                        int c=dp[j]+1;
                        dp[i]=max(dp[i],c);
                    }
                }
                
                else if(temp[i]<0){
                    if(temp[j]>0){
                        int c=dp[j]+1;
                        dp[i]=max(dp[i],c);
                    }
                }
                
                else{
                    dp[i]=max(dp[i],dp[j]);
                    cnt++;
                }
            }
           // if(dp[i]==-1)
             //dp[i]=1;
            
            if(dp[i]>omax)
                omax=dp[i];
        }
        if(cnt>2)
            return omax;
        return omax+1;
        
    }
};*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size() < 2) return nums.size();
        int down = 1;
        int up = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]) up = down +1;
            else if(nums[i] < nums[i-1]) down = up + 1;
        }
        return max(down, up);
        
    }
};