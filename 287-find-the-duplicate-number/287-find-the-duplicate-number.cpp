class Solution {
    int isPossible(vector<int>& nums,int mid){
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] <=mid)
                count++;
        }
        
        return count;
    }
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1,duplicate=0;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(isPossible(nums,mid) > mid){
                duplicate=mid;
                h=mid-1;
            }
            
            else
                l=mid+1;
        }
        
        return duplicate;
    }
};