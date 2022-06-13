//SLIDING WINDOW
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n=nums.size(),sum=0,ans=INT_MAX;
//         int j=0;
        
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
            
//             while(sum >= target){
//                 ans=min(ans,i-j+1);
//                 sum-=nums[j];
//                 j++;
//             }
//         }
        
//         if(sum<=target && j==0)
//             return 0;
        
//         return ans;
//     }
// };



class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int n=nums.size();
        int ans=INT_MAX,sum=0;
        
        vector<int> pref(n+1,0);
        pref[1]=nums[0];
        
        for(int i=2;i<n+1;i++){
            pref[i] = pref[i-1]+nums[i-1];
        }
        
        if(pref[n] < target)
            return 0;
        
        for(int i=1;i<n+1;i++){
            int l=i,h=n;
            
            while(l<=h){
                int mid=l+(h-l)/2;
                
                int cur_sum=pref[mid]-pref[i-1];
                if(cur_sum >=target){
                    ans=min(ans,mid-i+1);
                    h=mid-1;
                }
                
                else
                    l=mid+1;
            }
        }
        
        return ans;
    }
};























 