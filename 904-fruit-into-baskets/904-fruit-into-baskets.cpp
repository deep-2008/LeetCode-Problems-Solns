class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(),sp=0,ep=0,ans=0;
        unordered_map<int,int> mp;
        
        while(ep<n){
            mp[fruits[ep]]++;
            
            while(mp.size()>2){
                mp[fruits[sp]]--;
                
                if(mp[fruits[sp]]==0)
                    mp.erase(fruits[sp]);
                sp++;
            }
            
            ans=max(ans,ep-sp+1);
            ep++;
        }
        return ans;
    }
};