class Solution {
    int helper(string s,int k,int n,char c){
        if(n==1)
            return 1;
        
        int ans=1,sp=0,ep=0;
        
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
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        
        return max(helper(answerKey,k,n,'T'),helper(answerKey,k,n,'F'));
    }
};