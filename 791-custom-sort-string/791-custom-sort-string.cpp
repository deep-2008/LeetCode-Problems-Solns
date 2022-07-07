class Solution {
public:
    string customSortString(string orders, string s) {
        string ans="";
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        for(int i=0;i<orders.size();i++){
            if(mp.find(orders[i])!=mp.end()){
                while(mp[orders[i]]-->0){
                // mp[orders[i]]--;
                ans+=orders[i];
                }
            }
        }
        
        for(auto it:mp){
            if(it.second>0){
                while(it.second-->0)
                    ans+=it.first;
            }
        }
        
        return ans;
    }
};