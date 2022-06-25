class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();long long int sum=0;
        vector<long long int> pref(n+1,0);
        int m=pref.size();
        
        for(int i=0;i<n;i++){
            sum+=chalk[i];
            pref[i+1]=sum;
        }
        
        int rem=k%sum;
        
        if(rem==0)
        return 0;
        
        int ans=0,l=1,h=m-1;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(pref[mid]>rem){
                ans=mid-1;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        
        return ans;
    }
};