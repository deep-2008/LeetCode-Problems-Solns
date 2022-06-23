class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        
        for(int k=n-1;k>1 && nums[k]!=0;k--){
            int l=0,h=k-1;
            
            while(l<h){
                while(nums[l]==0 && l<h)
                    l++;
                
                while(nums[h]==0 && l<h)
                    h--;
                if(l>=h)
                    break;
                if(nums[l]+nums[h] > nums[k]){
                    count+=(h-l);
                    h--;
                }
                
                else
                    l++;
            }
        }
        
        return count;
    }
};