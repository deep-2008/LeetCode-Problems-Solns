#define mod 1000000009
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();
        
        unordered_map<int,int> mp;
        vector<int> result;
        vector<pair<int,int>> job;
        
        for(int i=0;i<n;i++){
            job.push_back({difficulty[i],profit[i]});
        }
        
        sort(job.begin(),job.end());
        
        for(int i=0;i<n;i++){
            mp[difficulty[i]]=profit[i];
        }
        
        sort(difficulty.begin(),difficulty.end());
        sort(worker.begin(),worker.end());
        
        if(worker[m-1]<difficulty[0])
            return 0;
        
        int j=0;
        int ans=0;
         int sum=0;
        
        for(int i=0;i<m;i++){
            
            int key=worker[i];
            
            
            while(j<n && key>=job[j].first)
                ans=max(ans,job[j++].second);
            
            sum+=ans;
            result.push_back(ans);
        }
        
       
        // for(auto i:result)
        //     sum+=i;
        
        return sum;
    }
};