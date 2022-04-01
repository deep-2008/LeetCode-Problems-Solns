class Solution {
public:
    string frequencySort(string s) {
        if(s.size()==1||s.size()==2)
            return s;
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        priority_queue<pair<int,char>> maxh;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            maxh.push({it->second,it->first});
        }
        int count=0;
        string ans;
        
        while(maxh.size()>0){
            count=maxh.top().first;
            char x=maxh.top().second;
            while(count>0){
                ans+=x;
                count--;
            }
            maxh.pop();
        }
        return ans;
    }
};