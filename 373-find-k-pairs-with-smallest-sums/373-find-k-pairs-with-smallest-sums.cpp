class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pair<long long,pair<int,int>>> pq;
         int m=nums1.size(),n=nums2.size();
        long long sum=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{nums1[i],nums2[j]}});
                }else if(sum<pq.top().first){
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }else break;
            }
        }
        
        vector<vector<int>> result;
        
        while(pq.size()>0){
            auto node=pq.top();
            pq.pop();
            
            vector<int> temp;
            temp.push_back(node.second.first);
            temp.push_back(node.second.second);
            result.push_back(temp);
        }           
        return result;
    }
};