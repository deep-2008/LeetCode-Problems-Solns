class Solution {
    int isPossible(vector<int>& bloom,int n,int m,int k,int mid){
        int ans=0,window=0;
        // int ep=0,sp=0;
        
//         while(ep<n){
//             if(bloom[ep]<=mid){
//                 window=ep-sp+1;
//                 if(window==k)
//                     ans++;
                
//                 if(window>k){
//                     sp++;
//                 }
//                 ep++;
//             }
//             else{
//                 while(ep<n && bloom[ep]>mid)
//                     ep++;
//                 sp=ep;
//             }
            
//         }
        
        for(int i=0;i<n;i++){
            if(bloom[i]<=mid)
                window++;
            
            else
                window=0;
            
            if(window==k){
            ans++;
                window=0;
            }
        }
        // ans=ans/k;
        
        if(ans>=m)
            return 1;
        return 0;
    }
public:
    int minDays(vector<int>& bloom, int m, int k) {
        int n=bloom.size();
        
        int l=1,h=INT_MIN,ans=INT_MAX;
        for(auto i:bloom)
            h=max(h,i);
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(isPossible(bloom,n,m,k,mid)){
                ans=min(ans,mid);
                h=mid-1;
                // cout<<ans;
            }
            
            else
                l=mid+1;
        }
        
        if(ans<INT_MAX)
            return ans;
        return -1;
    }
};