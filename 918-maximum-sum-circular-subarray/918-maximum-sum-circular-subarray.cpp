class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mini = INT_MAX;
        int sum = 0;
        int totalsum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum = sum + nums[i];
            totalsum += nums[i];
            mini = min(mini , sum);
            if(sum > 0){
                sum = 0;
            }
        }
        int ans = totalsum - mini;
        int maxi = INT_MIN;
        sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum = sum + nums[i];
            maxi = max(maxi , sum);
            if(sum < 0){
                sum = 0;
            }
        }
        if(totalsum == mini) return maxi;
        return max(ans , maxi);
    }
};