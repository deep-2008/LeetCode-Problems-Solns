#define ll long long int
class Solution {
    bool isPossible(vector<int>& candies,ll mid,ll k){
        ll count=0;
        
        for(auto i:candies){
            count+= (i/mid);
            if(count>=k)
                return true;
        }
        
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll n=candies.size();
        ll maxi=INT_MAX;
        
        for(auto i:candies){
           maxi = max(maxi,(1ll)*i); 
        }
        
        ll l=1,h=maxi,ans=0;
        
        while(l<=h){
            ll mid=l+(h-l)/2;
            
            if(isPossible(candies,mid,k)==1){
                ans=mid;
                l=mid+1;
            }
            
            else
                h=mid-1;
        }
        
        return ans;
    }
};