class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
         
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i)
                    temp.push_back(1);
                else{
                    int x=result[i-1][j-1]+result[i-1][j];
                    temp.push_back(x);
                }
            }
            result.push_back(temp);
        }
        
        return result;
    }
};