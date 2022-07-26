class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int sum=0,n=nums.size()-1;
        vector<int> res;
        
        for(auto i:nums)
            sum^=i;
        
        int k=(1<<maximumBit)-1;
        
        while(n>=0){
//             int ans=0,ind=0;
//             for(int i=0;i<=k;i++){
//                 int c=sum^i;
                
//                 if(c>ans){
//                     ans=c;
//                     ind=i;
//                 }
//                 // ans=max(ans,(sum^i));
//             }
            int ind=sum^k;
            res.push_back(ind);
            sum=sum^nums[n];
            n--;
        }
        return res;
    }
};