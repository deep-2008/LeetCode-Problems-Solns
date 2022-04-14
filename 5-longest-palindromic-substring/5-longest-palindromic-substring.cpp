class Solution {
public:
   /* string longestPalindrome(string s) {
         string ans;      
        int n=s.size();
        int dp[n][n],length=0;
        
        for(int g=0;g<n;g++){
            for(int j=g,i=0;j<n;j++,i++){
                if(g==0)
                    dp[i][j]=1;
                
                else if(g==1){
                    if(s[i]==s[j])
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]>0)
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                
                if(dp[i][j]>0){
                    length=g+1;
                    dp[i][j]=length;}
               
            }
        }
        int x=0,y=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(dp[i][j]==length){
                   x=i;y=j;
                   break;
               }
           }
       }
        if(s.size()%2==1){
        for(int i=x-1;i<y;i++)
            ans.push_back(s[i]);}
        else{
             for(int i=x;i<=y;i++)
            ans.push_back(s[i]);
        }
        return ans;
        }*/
    
    string longestPalindrome(string s) {
      int temp = 0, ans = 0, start, end;
      vector < vector < int >> dp(s.size(), vector < int > (s.size(), 0));
      while (temp < s.size()) {
        for (int row = 0, col = temp; row < s.size() - temp && col < s.size(); col++, row++) {
          if (col == row)
            dp[row][col] = 1;
          else if (s[col] == s[row] && col - row == 1)
            dp[row][col] = 1;
          else if (s[col] == s[row] && dp[row + 1][col - 1] == 1)
            dp[row][col] = 1;
          if (dp[row][col] == 1 && col - row + 1 > ans)
            ans = col - row + 1, start = row, end = col;
        }
        temp++;
      }
      return s.substr(start, end - start + 1);
    }
    
    
};