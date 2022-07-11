class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int K) {
        int n=nums.size();
        vector<int> ans(n,-1);
        
        
        long long int k=2*K+1;
        if(k>n)
            return ans;
        
        int sp=0,j=0;
        long long int sum=0;
        for(int i=0;i<k;i++)
            sum+=nums[i];
        
        ans[K+j]=sum/k;
        j++;
        
        for(int i=k;i<n;i++){
            sum-=nums[sp];
            sum+=nums[i];
            ans[K+j]=sum/k;
            sp++;j++;
        }
        return ans;
    }
};