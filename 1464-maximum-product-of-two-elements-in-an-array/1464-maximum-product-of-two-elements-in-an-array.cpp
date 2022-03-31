class Solution {
public:
    int maxProduct(vector<int>& nums) {
       priority_queue<int,vector<int>,greater<int>> minh;
        int k=2;
        for(int i=0;i<nums.size();i++){
            minh.push(nums[i]);
            
            if(minh.size()>k)
                minh.pop();
        }
        int ans=1;
        while(minh.size()>0){
            ans*=(minh.top()-1);
            minh.pop();
        }
        return ans;
    }
};