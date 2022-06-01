class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        long int prefsum=0;
        
        for(int i=0;i<nums.size();i++){
            prefsum+=nums[i];
           // result.push_back(prefsum);
            nums[i]=prefsum;
        }
        
       // return result;
        return nums;
    }
};