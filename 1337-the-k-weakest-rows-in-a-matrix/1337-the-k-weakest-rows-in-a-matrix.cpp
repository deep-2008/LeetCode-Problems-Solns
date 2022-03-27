class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       vector<int> result;
        set<pair<int,int>> mp;
        int count=0;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)
                    count++;
            }
            mp.insert({count,i});
            count=0;
        }
        
       for(auto i :mp){
           if(k==0)
               break;
           result.push_back(i.second);
           k--;
       }
        
        return result;
    }
};