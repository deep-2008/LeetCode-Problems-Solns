class Solution {
public:
    /*int dp[101][10002];
    
    int solve(int e,int f){
        if(e==1)
            return f;
        
        if(f==0||f==1)
            return f;
        
        if(dp[e][f]!=-1)
            return dp[e][f];
        
        int ans=INT_MAX,l,r;
        
        for(int k=1;k<=f;k++){
            
            if(dp[e-1][k-1]!=-1)
                 l=dp[e-1][k-1];
            
            else{
                l=solve(e-1,k-1);
                dp[e-1][k-1]=l;
            }
            
            
            if(dp[e][f-k]!=-1)
                 r=dp[e][f-k];
            
            else{
                r=solve(e,f-k);
                dp[e][f-k]=r;
            }
            
            
            int temp=1+max(l,r);//worst case checking hence maximum
            
            ans=min(temp,ans);// minimum no. of attempts
        }
        
        return dp[e][f]=ans;
    }
    
    int superEggDrop(int e, int f) {
        memset(dp,-1,sizeof(dp));
        
        return solve(e,f);
    }*/
    int tab[101][10001];
    int solve(int k,int n){
       if(n==0 || n==1)
           return n;
        if(k==1)
            return n;
        int mn=INT_MAX;
        if(tab[k][n]!=-1)
            return tab[k][n];
        int l=1;
        int h=n;
       while(l<=h){
            int i=l+((h-l)/2);
            int low,high;
            if(tab[k-1][i-1]!=-1)
                low=tab[k-1][i-1];
            else
            {
                low=solve(k-1,i-1);
                tab[k-1][i-1]=low;
            }
            if(tab[k][n-i]!=-1)
                high=tab[k][n-i];
            else{
                high=solve(k,n-i);
                tab[k][n-i]=high;
            }
            int temp=1+max(low,high);
            mn=min(mn,temp);
			
           if(high>low)
               l=i+1;
           else
               h=i-1;
        }
        return tab[k][n]=mn; 
    }
    int superEggDrop(int k, int n) {
     memset(tab,-1,sizeof(tab));
        return solve(k,n);
    }
};