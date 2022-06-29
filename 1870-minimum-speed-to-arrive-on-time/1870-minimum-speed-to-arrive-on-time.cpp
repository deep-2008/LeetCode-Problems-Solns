class Solution {
    int isPossible(vector<int>& dist,double hour, int mid){
        double time=0;
        // int temp=0;
        
        for(int i=0;i<dist.size();i++){
            time = ceil(time);
            
            time+=(double)dist[i]/mid;
            
            if(time>hour)
                return false;
        }
        
//         time =(double)temp;
        
//         time+=(dist[dist.size()-1])/mid;
        
//         if(time>hour)
//             return 0;
        return true;
    }
    
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        
       //long long int sum=0;//accumulate(dist.begin(),dist.end(),0);
         int ans=INT_MAX;
         int l=1,h=INT_MAX-1;
        
        while(l<=h){
           int mid=l+(h-l)/2;
            
            if(isPossible(dist,hour,mid)){
                ans=min(ans,mid);
                h=mid-1;
            }
            
            else
                l=mid+1;
        }
        
        if(ans==INT_MAX)
            return -1;
        
        // int ans2=0;
        // ans2=(1ll)*ans;
        
        return ans;
     }
};

