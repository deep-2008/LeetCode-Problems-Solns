//#define pll pair<int,pair<int,int>>;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxh;
        
        for(int i=0;i<points.size();i++){
            int x=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            maxh.push({x,{points[i][0],points[i][1]}});
            
            if(maxh.size()>k)
                maxh.pop();
        }
        vector<vector<int>> result;
        while(maxh.size()>0){
            vector<int> temp;
            temp.push_back(maxh.top().second.first);
            temp.push_back(maxh.top().second.second);
            result.push_back(temp);
            maxh.pop();
        }
        return result;
    }
};