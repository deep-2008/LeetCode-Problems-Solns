class Solution {
    int isPossible(vector<int>& q,int n,int mid){
        int k=0;
        
        for(int i=0;i<q.size();i++){
            if(q[i]%mid==0){
                k=k+(q[i]/mid);
            }
            else
                k=k+(q[i]/mid)+1;
            
            if(k>n)
                return 0;
        }
        return 1;
    }
    
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
       int m=quantities.size();
        int h=INT_MIN;
        
        for(int i=0;i<m;i++)
            h=max(h,quantities[i]);
        
        int l=1,ans=0;
        
        while(l<=h){
            long long int mid=l+(h-l)/2;
            
            if(isPossible(quantities,n,mid)){
                ans=mid;
                h=mid-1;
            }
            
            else
                l=mid+1;
        }
        
        return ans;
    }
};