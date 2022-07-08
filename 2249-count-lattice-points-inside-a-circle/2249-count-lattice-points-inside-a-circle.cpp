class Solution {
    int dp[101][101],ans=0;
    
    
public:
    int countLatticePoints(vector<vector<int>> circles) {
        unordered_set<int> res;
        for (auto& c : circles){
            for (int i = -c[2]; i <= c[2]; i++){
                for (int j = -c[2]; j <= c[2]; j++){
                    if (i * i + j * j <= c[2] * c[2])
                        res.insert((c[0] + i) * 1000 + c[1] + j);
                }
            }
        }
        return res.size();
    
    }
};