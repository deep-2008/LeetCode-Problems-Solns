class Solution {
    int dp[366];
    int helper(int cday,vector<int>& days,vector<int>& costs,unordered_map<int,int>& travel_today){
        if(cday>days[days.size()-1])
            return 0;
        
        if(dp[cday]!=-1)
            return dp[cday];
        
        int ans=INT_MAX;
        if(travel_today.find(cday)!=travel_today.end()){
            ans=helper(cday+1,days,costs,travel_today)+costs[0];
            
            ans=min(ans,helper(cday+7,days,costs,travel_today)+costs[1]);
            
            ans=min(ans,helper(cday+30,days,costs,travel_today)+costs[2]);
        }
        else
            return helper(cday+1,days,costs,travel_today);
        
        return dp[cday]=ans;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        
        unordered_map<int,int> mp;
        
        for(auto i:days)
            mp[i]=1;
        
        return helper(1,days,costs,mp);
    }
};