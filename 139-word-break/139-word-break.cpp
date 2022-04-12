/*class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        int dp[n+1];
      //  memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
               string check=s.substr(j,i+1);
                if(wordDict.find(check)!=wordDict.end())
                    dp[i]+=dp[j];
            }
        }
        
        if(dp[n]>0)
            return true;
        return false;
    }
};*/

class Solution {
public:
bool wordBreak(string s, vector<string>& wordDict) {
vector reachable(s.length(), false);
for (auto idx = 0; idx < s.length(); ++idx) {
if (idx !=0 && reachable[idx-1] == false)
continue;
for (auto &word : wordDict) {
if (idx+word.length() > s.length())
continue;
if (s.substr(idx,word.length()) == word)
reachable[idx+word.length()-1] = true;
}
}

    return reachable.back();
}
};