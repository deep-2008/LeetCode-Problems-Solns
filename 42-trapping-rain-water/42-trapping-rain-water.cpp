class Solution {
public:
    int trap(vector<int>& height) {
        //PREF SUM
        
        int n=height.size();
        int ans=0,c=0,d=0;
        vector<int> pref(n,0),suff(n,0);
        
        for(int i=0;i<n;i++){
             c=max(c,height[i]);
             d=max(d,height[n-i-1]);
            pref[i]=c;
            suff[n-i-1]=d;
        }
        
        for(int i=0;i<n;i++){
            int c=min(pref[i],suff[i])-height[i];
            ans+=c;
        }
        
        return ans;
    }
};