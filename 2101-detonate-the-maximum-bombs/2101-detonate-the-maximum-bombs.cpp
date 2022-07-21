class Solution {
public:
     bool isConnected(vector<vector<int>>& bombs, int i, int j){
        long long diffX=bombs[i][0]-bombs[j][0];
        long long diffY=bombs[i][1]-bombs[j][1];
        diffX*=diffX;
        diffY*=diffY;
        long long sum=diffX+diffY;
        double dist=(double)sqrt((double)sum);
        if(dist<=bombs[i][2]) return true;
        else return false;
    }
    
	//Using dfs to find how many bombs are in the range of i
   void dfs(vector<vector<int>>& connected, vector<bool>& visited, int i, int& count){
        visited[i]=true;
        for(int j=0; j<connected.size(); j++){
            if(visited[j]==false && connected[i][j]==1){
                count=count+1;
                dfs(connected, visited, j, count);
            }
        }
    }
	
	//Main Function
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> connected(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected(bombs, i, j)) connected[i][j]=1;
            }
        }
        int maxCount=INT_MIN;
        for(int i=0; i<n; i++){
            int count=1;
            vector<bool> visited(n, false);
            dfs(connected, visited, i, count);
            if(count>maxCount) maxCount=count;
        }
        return maxCount;
    }
};