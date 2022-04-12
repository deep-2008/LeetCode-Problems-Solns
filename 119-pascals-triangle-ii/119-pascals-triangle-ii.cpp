class Solution {
public:
    vector<int> getRow(int rowIndex) {
      //  vector<vector<int>> result;
        vector<int> result;
        for(int i=0;i<rowIndex+1;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i)
                    temp.push_back(1);
                else{
                    //int x=result[i-1][j-1]+result[i-1][j];
                    int x=result[j-1]+result[j];
                    temp.push_back(x);
                }
            }
            //result.push_back(temp);
            result=temp;
        }
        //return result[rowIndex];
        return result;
    }
};