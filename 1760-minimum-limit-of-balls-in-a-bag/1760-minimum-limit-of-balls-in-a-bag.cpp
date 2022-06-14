class Solution {
    int isPossible(vector<int>& nums,long long int mid,int op){
        long long int count=0;
        
        for(long long int i=0;i<nums.size();i++){
            count+= (nums[i]-1)/mid;
            
            if(count>op)
                return 0;
        }
        
        return 1;
    }
    
public:
    int minimumSize(vector<int>& nums, int op) {
        long long int n=nums.size();
        long long int maxi=INT_MIN;
        
        for(long long int i=0;i<n;i++){
            maxi=max(maxi, (1ll)*nums[i]);
        }
        
        
        long long int l=1,h=maxi,ans=0;
        
        while(l<=h){
            long long int mid=l+(h-l)/2;
            
            if(isPossible(nums,mid,op) ==1){
                ans =mid;
                h=mid-1;
            }
            
            else
                l=mid+1;
        }
        
        return ans;
    }
};