#define ll long long int
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n=nums.size();
        ll temp=INT_MAX,ans=0;
        
        vector<ll> pref(n+1,0);
        //pref[1]=nums[0];
        
        for(ll i=1;i<n+1;i++){
            pref[i] = pref[i-1]+nums[i-1];
        }
        
//         if((pref[n]*n) < k)
//             return 0;
        
        for(ll i=1;i<n+1;i++){
            ll l=i,h=n;
            
            ll tempAns=-1;
            
            while(l<=h){
                ll mid=l+(h-l)/2;
                
                ll curr_score = (pref[mid]-pref[i-1])*(mid-i+1);
                
                if(curr_score >= k){
                    h=mid-1;
                }
                
                else{
                    // temp=min(temp,mid-i+1);
                    tempAns = (mid-i+1);
                    l=mid+1;
                }
            }
            
            if(tempAns!=-1)
                ans+= tempAns;
        }
        
        return ans;
    }
};