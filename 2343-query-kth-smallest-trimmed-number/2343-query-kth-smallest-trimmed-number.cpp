// class Solution {
// public:
//     vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
//         int n=queries.size(),m=nums.size();
//         vector<int> ans(n,0);
        
//         for(int i=0;i<n;i++){
//             int k=queries[i][0];
//             int trim=queries[i][1];
//             priority_queue<pair<string,int>> maxh;
            
//             for(int j=0;j<m;j++){
//                 string temp=nums[j];
//                 int size=temp.size();
//                 // string trimmed="0";
                
//                 int t=nums[j].length()-trim;
//                 string p=nums[j].substr(t,trim);
                
//                 maxh.push({p,j});
//                 if(maxh.size()>k)
//                     maxh.pop();                
//             }
//             ans[i]=maxh.top().second;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto x:queries)
        {
            priority_queue<pair<string,int>> v;
            for(int i=0;i<nums.size();i++)
            {
                int t=nums[i].length()-x[1];
                string p=nums[i].substr(t,x[1]);
                if(v.size()<x[0])
                    v.push({p,i});
                else
                {
                    if(v.top().first > p)
                    {
                        v.pop();
                        v.push({p,i});
                    }
                }
            }
            int val=v.top().second;
            res.push_back(val);
        }
        return res;
    }
};