class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int b=INT_MAX,profit=0;
        
        for(int i=0;i<n-1;i++){
           //b=min(b,prices[i]);
            
            if(prices[i+1]>prices[i]){
               profit+= (prices[i+1]-prices[i]);
                
            }
        }
        
        return profit;
    }
};