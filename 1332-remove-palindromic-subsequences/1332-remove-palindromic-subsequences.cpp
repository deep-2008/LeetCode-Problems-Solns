class Solution {
public:
    int removePalindromeSub(string s) {
        int n=s.size();
        int l=0,h=n-1;
        
        if(n==1)
            return 1;
        
        while(l<=h){
            if(s[l]!=s[h])
                return 2;
            l++;h--;
        }
        
        return 1;
    }
};