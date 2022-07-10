class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        
        int ans=0;
        if(homePos[0]>startPos[0]){
            for(int i=startPos[0];i<homePos[0];i++){
                ans+=rowCosts[i+1];
            }
            
        }
        
        else{
            for(int i=startPos[0];i>homePos[0];i--)
                ans+=rowCosts[i-1];
        }
        
        if(homePos[1]>startPos[1]){
            for(int i=startPos[1];i<homePos[1];i++)
                ans+=colCosts[i+1];
        }
        
        else{
            for(int i=startPos[1];i>homePos[1];i--)
                ans+=colCosts[i-1];
        }
        
        return ans;
    }
};