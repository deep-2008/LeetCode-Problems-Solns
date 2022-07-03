class Solution {
public:
  // static bool comp(vector<int> a, vector<int> b){
    //return (a>b);
//}
    bool possible(vector<int> &nums,int mid,int k){
        long long int windowsum = 0, totalsum = 0;
        
        for(int i=0;i<mid;i++)
            windowsum+=nums[i];
            
            totalsum = 1ll*nums[mid-1]*mid;
            
            if(totalsum-windowsum <= k)
                return true;
            
            int j=0;
            for(int i=mid;i<nums.size();i++){
               windowsum-=nums[j];
                windowsum+=nums[i];
                totalsum=1ll*nums[i]*mid;
                
                if(totalsum - windowsum <=k)
                    return 1;
                j++;
            }
        return 0;
        
    }
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size(),result = 0;
        sort(nums.begin(),nums.end());
        int l=1,h=n;
        
        while(l<=h){
            int mid = (l+h)/2;
            
            if(possible(nums,mid,k)){
                result = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return result;
    }
};