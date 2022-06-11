class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end(),greater<int>());
       long long int totalBeans=0;
        int n=beans.size();
        long long int ans=LONG_MAX;
        
        for(auto i:beans)
            totalBeans+=i;
        
        for(int i=0;i<n;i++){
            long long savedBeans= (long long)beans[i]*(long long)(i+1);
            
            long long removedBeans=(totalBeans-savedBeans);
            
            ans = min(ans,removedBeans);
        }
        
//         int avg=sum/n;
        
//         long long int ans=0;
//         int ind=0;
//         for(int i=0;i<n;i++){
//             if(beans[i]<avg){
//                 ans+=beans[i];
//             }
            
//             else{
//               ind=i;
//                 sum=beans[i];
//                 break;
//             }
//         }
//         for(int i=ind;i<n;i++){
//             int c=beans[i]-sum;
//             ans+=c;
//         }
        
        
        return ans;
    }
};