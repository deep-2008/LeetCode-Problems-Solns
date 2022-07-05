class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> minh;
        
        for(auto i:nums)
            minh.push(i);
        
        int csum=0,osum=0,prev=INT_MIN;
        
        while(minh.size()>0){
            int node=minh.top();
            minh.pop();
            
            if(prev==node)
                continue;
            
            if(prev==INT_MIN){
                csum=1;
            }
            
            else{
                if(prev+1==node)
                    csum++;
                else
                    csum=1;
            }
            
            osum=max(csum,osum);
             prev=node;
        }
        return osum;
    }
};