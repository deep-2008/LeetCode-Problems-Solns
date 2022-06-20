class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s1(words.begin(),words.end());
        set<string> fin(words.begin(),words.end());
        
        for(auto it:s1){
            for(int i=1;i<it.size();i++){
                fin.erase(it.substr(i));
            }
        }
        
        int ans=0,count=0;
        
        for(auto it:fin){
            ans+=it.size();
            count++;
        }
        
        ans+=count;
        return ans;
    }
};