class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),p=0;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                p=i+1;
                break;
            }
        }
        
        vector<pair<int,int>> temp;
        for(int i=p;i<n;i++){
            temp.push_back({nums[i],i});
        }
        
        for(int i=0;i<p;i++)
            temp.push_back({nums[i],i});
        
        int l=0,h=temp.size()-1,mid=0;
        
        while(l<=h){
            mid=(l+h)/2;
            
            if(temp[mid].first > target)
                h=mid-1;
            
            else if(temp[mid].first < target)
                l=mid+1;
            
            else{
                return temp[mid].second;
            }
        }
        
        return -1;
    }
};