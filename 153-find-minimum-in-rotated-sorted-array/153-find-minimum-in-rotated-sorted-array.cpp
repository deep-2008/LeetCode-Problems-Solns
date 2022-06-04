class Solution {
public:
    int findMin(vector<int>& nums) {
         int n=nums.size(),p=0;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                p=i+1;
                break;
            }
        }
        return nums[p];
        
//         vector<int> temp;
//         for(int i=p;i<n;i++){
//             temp.push_back(nums[i]);
//         }
        
//         for(int i=0;i<p;i++)
//             temp.push_back(nums[i]);
        
//         return temp[0];
    }
};