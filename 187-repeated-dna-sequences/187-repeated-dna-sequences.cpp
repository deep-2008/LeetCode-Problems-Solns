class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // return {"AAAAACCCCC","AAAAACCCCC"};
        unordered_map<string,int> mp;
        if(s.size()<10)
            return {};
        
        for(int i=0;i<s.size()-10+1;i++){
            string temp=s.substr(i,10);
            mp[temp]++;
        }
        
        vector<string> ans;
        for(auto it:mp){
            if(it.second>1){
                // cout<<it.first<<" -> "<<it.second;
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};