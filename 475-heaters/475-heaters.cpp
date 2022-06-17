// class Solution {
//      int js=-1,jl=-1;
    
//     void binarySearch(vector<int>& heaters,int key){
//         int l=0,h=heaters.size()-1;
        
//         while(l<=h){
//             int mid=(h+l)/2;
            
//             if(heaters[mid]==key){
//                 js=heaters[mid];
//                 jl=heaters[mid];
//                 break;
//             }
            
//             else if(heaters[mid] > key){
//                 jl=heaters[mid];
//                 h=mid-1;
//             }
            
//             else{
//                 js=heaters[mid];
//                 l=mid+1;
//             }
//         }
//     }
    
    
// public:
//     int findRadius(vector<int>& houses, vector<int>& heaters) {
//         int n=houses.size();
//         int m=heaters.size();
//         int ans=INT_MIN;
//        // int temp=INT_MAX;
       
        
        
//         sort(heaters.begin(),heaters.end());
        
//         for(int i=0;i<n;i++){
//             int hp=houses[i];
            
//             binarySearch(heaters,hp);
//             // int d1=0,d2=0;
            
//             int d1 =(js==-1)?INT_MAX:(hp-js);
//             int d2 = (jl==-1)?INT_MAX:(jl-hp);
// //             if(js==-1)
// //                 d1=INT_MAX;
// //             else
// //                 d1=hp-js;
            
// //             if(jl==-1)
// //                 d2=INT_MAX;
// //             else
// //                 d2=jl-hp;
           
//             int temp=min(d1,d2);
            
//             ans=max(ans,temp);
            
//         }
        
//         return ans;
//     }
// };





class Solution {
public:
   
    int floor(vector<int> &a, int x) {
        int low = 0, high = a.size() - 1;
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(a[mid] <= x) {
                ans = a[mid];
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
    
    int ceil(vector<int> &a, int x) {
        int low = 0, high = a.size() - 1;
        int ans  = INT_MAX;
        while(low <= high) {
             int mid = (low + high) >> 1;
             if(a[mid] >= x) {
                 ans = a[mid];
                 high = mid - 1;
             } else low = mid + 1;
        }
        
        return ans;
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size();
        sort(heaters.begin(), heaters.end());
        vector<int> l(n), r(n);
        for(int i = 0; i < n; i++) {
            l[i] = floor(heaters, houses[i]);
            r[i] = ceil(heaters, houses[i]);
        }
        int ans = -1;
        for(int i = 0; i < n; i++) {
            
            int curMinDistance = INT_MAX;
            if(l[i] != -1) curMinDistance = min(curMinDistance, (houses[i] - l[i]));
            if(r[i] != INT_MAX) curMinDistance = min(curMinDistance, r[i] - houses[i]);
            
            ans = max(ans ,curMinDistance);
            
        }
        
        return ans;
        
    }
};