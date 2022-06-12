class Solution {
    bool isPossible(vector<int>& w,int mid,int days){
        int sum=0,d=1;
        
        for(int i=0;i<w.size();i++){
            sum+=w[i];
            
            if(sum >mid){
                d++;
                sum=w[i];
            }
        }
        
        return d<=days;
    }
    
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        
        int maxi=INT_MIN,sum=0;
        
        for(int i=0;i<n;i++){
            sum+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        
        if(n==days)
            return maxi;
        
        int l=maxi,h=sum;
        int ans=0;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
           if(isPossible(weights,mid,days)){
               ans=mid;
               h=mid-1;
           }
            
            else{
                l=mid+1;
            }
        }
        
        return ans;
    }
};