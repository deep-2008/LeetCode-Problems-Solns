class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        
        //using ordered map --> stores array values as key and index as value
        map<int,int> bounds;
        
        //2D DP --> state 1 is for index, state 2 for odd vs even jump
        vector<vector<bool>> dp(n,vector<bool>(2));
        
        //base case-->last index is always good index
        dp[n-1][0]=true;
        dp[n-1][1]=true;
        
        //add to map
        bounds[arr[n-1]]=n-1;
        //check in reverse
        for(int i=n-2;i>=0;--i){
            //first check for equal elemnents
            if(bounds.find(arr[i])!=bounds.end()){
                int j=bounds[arr[i]];
                dp[i][1]=dp[j][0];
                dp[i][0]=dp[j][1];
            }
            else{
                auto it=bounds.upper_bound(arr[i]);

                //upper bound not found
                //no element on right is greater than arr[i]
                //odd numbered jump not possible
                if(it==bounds.end())
                    dp[i][1]=false;

                //upper bound is found
                //odd numbered is possible 
                //i is a good index if upper bound is good index with even jumps
                else
                    dp[i][1]=dp[it->second][0];

                //no value smaller than arr[i]
                //even jumps are not possible from here
                if(it==bounds.begin())
                    dp[i][0]=false;

                //it-- point to element smaller than upper bound
                //this must be greatest element smaller than arr[i]
                else{
                    --it;
                    dp[i][0]=dp[it->second][1];
                }
            }
            
            bounds[arr[i]]=i;
        }
        
        int ans=0;
        for(int i=0;i<n;++i)
            //first jump is always an odd jump
            if(dp[i][1])
                ans++;
        return ans;
        
    }
};