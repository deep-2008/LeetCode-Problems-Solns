class Solution {
public:
   // #define mod 1e9+7;
    int threeSumMulti(vector<int>& arr, int X) {
        unordered_map<int,int> mp;
        int ans=0,n=arr.size(),mod=1e9+7;
        
        for(int i=0;i<n;i++){
            ans= (ans+mp[X - arr[i]]) % mod;
            for(int j=0;j<i;j++){
                mp[arr[i] + arr[j]]++;
            }
        }
        
        return ans;
    }
};