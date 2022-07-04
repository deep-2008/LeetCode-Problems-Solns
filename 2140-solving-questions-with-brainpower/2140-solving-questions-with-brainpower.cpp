class Solution {
    long long solver(vector<vector<int>>& ques,vector<long long int>& dp,int ind,int n){
        if(ind>=n){
            return 0;
        }
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int points=ques[ind][0];
        int brain=ques[ind][1];
        int next_call=ind+brain+1;
        
        // if(next_call>=n)
        //     return dp[next_call-(brain+1)];
        
       return dp[ind]= max(points+solver(ques,dp,next_call,n),solver(ques,dp,ind+1,n));
        
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        
        vector<long long int> dp(n,-1);
        
        
        return solver(questions,dp,0,n);
    }
};