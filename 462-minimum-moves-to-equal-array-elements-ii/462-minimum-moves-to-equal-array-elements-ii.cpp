class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        int mid=l+(h-l)/2;
        sort(nums.begin(),nums.end());
        
        int ans=0;
        int median=nums[mid];
        
        for(int i=0;i<n;i++){
            ans+= abs(nums[i]-nums[mid]);
        }
        
        return ans;
    }
};