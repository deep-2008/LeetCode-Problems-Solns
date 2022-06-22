#define ll long long int
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
       int n=nums.size();
       ll sum=0;
        
        vector<ll> pref(n+1,0);
        
        for(int i=1;i<n+1;i++){
            sum+=nums[i-1];
            pref[i]=sum;
        }
        
        int ans=INT_MAX,ind=0,m=pref.size();
        for(int i=1;i<m;i++){
            int left = pref[i]/i;
            int right=0;
            
            if(i<m-1)
             right=(pref[m-1]-pref[i])/(m-i-1);
            
            else
              right=0;
            
            int c=abs(left-right);
            // cout<<c<<" ";
            if(c < ans){
                ans=c;
                ind=i-1;
            }
        }
        
        return ind;
    }
};