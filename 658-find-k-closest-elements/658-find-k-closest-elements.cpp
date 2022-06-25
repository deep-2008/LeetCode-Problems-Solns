class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n=arr.size();
        
//         if(x<=arr[0]){
//             for(int i=0;i<k;i++)
//                 ans.push_back(arr[i]);
//             return ans;
//         }
        
//         if(x>=arr[arr.size()-1]){
//             for(int i=0;i<k;i++)
//                 ans.push_back(arr[n-i-1]);
            
//             sort(ans.begin(),ans.end());
//             return ans;
//         }
//         return {0};
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        
        for(auto i:arr){
            int sum=abs(x-i);
            minh.push({sum,i});
        }
        
        for(int i=0;i<k;i++){
            int top=minh.top().second;
            ans.push_back(top);
            minh.pop();
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};