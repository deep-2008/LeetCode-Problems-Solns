class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int buy=INT_MAX,profit=0,ind=0,sell=0;
        // vector<int> dp(n,0);
        // int profit=0;
        
       for(int i=0;i<n;i++){
           buy=min(buy,nums[i]);
           sell=nums[i]-buy;
           profit=max(profit,sell);
       }
        return profit;
    }
};

