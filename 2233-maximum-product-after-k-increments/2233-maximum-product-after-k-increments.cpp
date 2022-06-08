#define mod (1000000000+7)
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();
        int zero=0;
        
        // sort(nums.begin(),nums.end());
        
//         for(auto i:nums){
            
//             if(i!=0)
//                 break;
//             zero++;
//         }
        
//         if(zero > k)
//         return 0;
        
        priority_queue<int,vector<int>,greater<int>> minh;
        
        for(auto i:nums)
            minh.push(i);
        
        while(k>0){
            int s=minh.top();
            minh.pop();
            s++;
            minh.push(s);
            k--;
        }
        
        long long int c=1;
        
        while(!minh.empty()){
            int a=minh.top();
            minh.pop();
            
            c = (c*a)%mod;
        }
        
        int ans = c%mod;
        
     //   c=c%mod;
        // int ans;
        return ans;
    }
};