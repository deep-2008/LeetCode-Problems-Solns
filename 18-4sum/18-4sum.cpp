#define mod 1e9
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //INTEGER OVERFLOW PROBLEM---CODE CORRECT
//         int n=nums.size();
        
//         vector<vector<int>> ans;
        
//         if(n<4)
//             return ans;
        
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<n-3;i++){
//             for(int j=i+1;j<n-2;j++){
//                 int l=j+1,r=n-1;
                
//                 while(l<r){
//                     long long int sum=(long long int)(nums[i]+nums[j]+nums[l]+nums[r]);
                    
//                     if(sum==target){
//                         ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        
//                         while(l<r && nums[l]==nums[l+1])
//                             l++;
//                         while(l<r && nums[r]==nums[r-1])
//                             r--;
//                         l++;r--;
//                     }
//                     else if(sum<target)
//                         l++;
//                     else
//                         r--;
//                 }
//                 while(j<n-2 && nums[j]==nums[j+1])
//                     j++;
//             }
            
//             while(i<n-3 && nums[i]==nums[i+1])
//                     i++;
//         }
        
//         return ans;
        
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(i > 0 && nums[i] == nums[i-1]){
                    continue;
                }
            for(int j = i + 1; j < n; j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                        continue;
                    }
                int y = nums[j];
                int k = j + 1;
                int m = n - 1;
                int rem = target - (x + y);
                while(k < m){
                    if(m < (n-1) && nums[m] == nums[m+1]){
                        m--;
                        continue;
                    }
                    if(nums[k]+nums[m] < rem){
                        k++;
                    }
                    else if(nums[k]+nums[m] > rem){
                        m--;
                    }
                    else{
                        result.push_back({x, y, nums[k], nums[m]});
                        k++;
                        m--;
                    }
                }
            }
        }
        return result;
    }
};