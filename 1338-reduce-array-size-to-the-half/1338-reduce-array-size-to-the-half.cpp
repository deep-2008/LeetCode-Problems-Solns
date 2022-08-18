class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        priority_queue<pair<int,int>> maxh;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            maxh.push({it->second,it->first});
        }
        int count=0;
        int m=n/2;
        while(n>m){
            count++;
            n-=maxh.top().first;
            maxh.pop();
        }
        return count;
    }
};