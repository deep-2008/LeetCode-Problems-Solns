class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum=0;
        vector<int> diff;
        
        for(int i=0;i<costs.size();i++){
            //for(int j=0;j<costs[i].size();j++){
                sum+=costs[i][0];
            //}
        }
        for(int i=0;i<costs.size();i++){
            int x=costs[i][1] - costs[i][0];
            diff.push_back(x);
        }
        
        sort(diff.begin(),diff.end());
        int n=diff.size();
        
        for(int i=0;i<n/2;i++){
            sum+=diff[i];
        }
        
        return sum;
        
    }
};