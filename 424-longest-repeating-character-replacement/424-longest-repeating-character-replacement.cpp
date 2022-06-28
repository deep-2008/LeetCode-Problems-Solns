class Solution {
    int helper(string s,int k,int n,char c){
        int ans=1;
        int sp=0,ep=0;
        
        while(ep<n){
            if(s[ep]!=c){
                if(k>0){
                    k--;
                }
                else{
                    
                    while(s[sp]==c)
                        sp++;
                    
                    sp++;
                }
            }
            
            ans=max(ans,ep-sp+1);
            ep++;
        }
        
        return ans;
        
    }
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        
        unordered_map<char,int> mp;
        for(auto i:s)
            mp[i]++;
        
        for(auto it:mp){
            ans=max(ans,helper(s,k,n,it.first));
        }
        
        return ans;
    }
};