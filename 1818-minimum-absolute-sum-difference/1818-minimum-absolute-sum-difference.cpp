// #define mod 1000000009
// class Solution {
//     // #define int long long int
//     long long int jl=-1,js=-1;
// public:
//     int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size();
        
//        long long int diff=0;
//         long long int max_diff=INT_MIN,ind=0;
//         int sum=0;
        
//         for(int i=0;i<n;i++){
            
//             diff=abs(nums1[i]-nums2[i]);
//             sum+=abs(nums1[i]-nums2[i])%mod;
            
//             if(diff>max_diff){
//                 max_diff=diff;
//                 ind=i;
//             }
//         }
        
//         if(sum==0)
//             return 0;
        
//         int key=nums2[ind];
//         // nums1[ind]=INT_MIN;
//         int l=1,h=n-1;
//         sort(nums1.begin(),nums1.end());
        
//         while(l<=h){
//             int mid=l+(h-l)/2;
            
//             if(nums1[mid]==key){
//                 jl=key;
//                 js=key;
//                 break;
//             }
            
//             else if(nums1[mid]<key){
//                 js=nums1[mid];
//                 l=mid+1;
//             }
            
//             else{
//                 jl=nums1[mid];
//                 h=mid-1;
//             }
//         }
        
//         if(jl==-1)
//             key=key-js;
//         else if(js==-1)
//             key=jl-key;
        
//         else{
//             if((jl-key) <= (key-js))
//                 key=abs(key-jl);
//             else
//                 key=abs(key-js);
//         }
            
        
//         sum=(sum-max_diff+key)%mod;
//         return sum;     
                
//     }
// };
class Solution{
public:
int minAbsoluteSumDiff(vector<int>& n1, vector<int>& n2) {
    long res = 0, gain = 0;
    set<int> s(begin(n1), end(n1));
    for (int i = 0; i < n1.size(); ++i) {
        long original = abs(n1[i] - n2[i]);
        res += original;
        if (gain < original) {
            auto it = s.lower_bound(n2[i]);
            if (it != end(s))
                gain = max(gain, original - abs(*it - n2[i]));
            if (it != begin(s))
                gain = max(gain, original - abs(*prev(it) - n2[i]));
        }
    }
    return (res - gain) % 1000000007;
}
};