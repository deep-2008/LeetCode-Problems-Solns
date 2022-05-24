class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0,maxl=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                left++;
            else
                right++;
            
            if(left==right)
                maxl = max(maxl,left);
            
            else if(right>left){
                left=0;
                right=0;
            }
        }
        
        left=0;right=0;
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(')
                left++;
            else
                right++;
            
            if(left==right)
                maxl=max(maxl,right);
            
            else if(left>right){
                right=0;
                left=0;
            }
        }
        
        return maxl*2;
    }
};