#define vii vector<vector<int>>
#define vi vector<int>
//BRUTE FORCE
/*class Solution {
    void lightupgrid(vii &grid,int row,int col,int n){
        int r=row,c=col;
        
        while(r>=0){
            if(grid[r][c] !=-1)
                grid[r][c]++;
            r--;
        }
        r=row;
        
         while(r<n){
            if(grid[r][c] !=-1)
                grid[r][c]++;
            r++;
        }
        r=row;
        
         while(c>=0){
            if(grid[r][c] !=-1)
                grid[r][c]++;
            c--;
        }c=col;
        
         while(c<n){
            if(grid[r][c] !=-1)
                grid[r][c]++;
            c++;
        }c=col;
        
         while(r>=0 && c>=0){
            if(grid[r][c] !=-1)
                grid[r][c]++;
            r--;c--;
        }r=row;c=col;
        
        while(r<n && c<n){
            if(grid[r][c] !=-1)
                grid[r][c]++;
            r++;c++;
        }r=row;c=col;
        
        while(r>=0 && c<n){
            if(grid[r][c] !=-1)
                grid[r][c]++;
            r--;c++;
        }r=row;c=col;
        
        while(r<n && c>=0){
            if(grid[r][c] !=-1)
                grid[r][c]++;
            r++;c--;
        }r=row;c=col;
    }
    
    void turnOffAdjacent(vii &grid,int row,int col,int n){
        
        int r=row,c=col;
        
        while(r>=0){
            if(grid[r][c] > 0)
                grid[r][c]--;
            r--;
        }
        r=row;
        
         while(r<n){
            if(grid[r][c] >0)
                grid[r][c]--;
            r++;
        }
        r=row;
        
         while(c>=0){
            if(grid[r][c] >0)
                grid[r][c]--;
            c--;
        }c=col;
        
         while(c<n){
            if(grid[r][c] >0)
                grid[r][c]--;
            c++;
        }c=col;
        
         while(r>=0 && c>=0){
            if(grid[r][c] >0)
                grid[r][c]--;
            r--;c--;
        }r=row;c=col;
        
        while(r<n && c<n){
            if(grid[r][c] >0)
                grid[r][c]--;
            r++;c++;
        }r=row;c=col;
        
        while(r>=0 && c<n){
            if(grid[r][c] >0)
                grid[r][c]--;
            r--;c++;
        }r=row;c=col;
        
        while(r<n && c>=0){
            if(grid[r][c] >0)
                grid[r][c]--;
            r++;c--;
        }r=row;c=col;
    }
    
    void neighbourChecker(vii &grid,int row,int col,int n){
        vii dirs = {{0,0},{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};
        
        for(int i=0;i<dirs.size();i++){
            int r=row+dirs[i][0];
            int c=col+dirs[i][1];
            
            if(r<0 || c<0 || r==n || c==n)
                continue;
            
            if(grid[r][c] == -1){
                grid[r][c]=0;
                turnOffAdjacent(grid,r,c,n);
            }
                
        }
    }
    
    
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        
        vector<vector<int>> grid(n,vector<int> (n,0));
        vector<int> ans(queries.size(),0);
        
        for(int i=0;i<lamps.size();i++){
            int u=lamps[i][0];
            int v=lamps[i][1];
            
            grid[u][v]=-1;
            lightupgrid(grid,u,v,n);
        }
        
        
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            
            if(grid[u][v]>0 || grid[u][v]==-1){
                ans[i]=1;
            }
            
            neighbourChecker(grid,u,v,n);
            
        }
        
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<grid[i][j]<<" ";
        //     }cout<<endl;
        // }
        
        return ans;
    }
};*/


//OPTIMISED

class Solution {
    unordered_map<int, int> row, col, positiveDiag, negativeDiag;
    set<pair<int, int>> litLamps;
public:
    
    bool isLit(int i, int j){
        
        if(row[i] != 0 || col[j] != 0 || positiveDiag[i + j] != 0 || negativeDiag[i - j] != 0) return true;
        
        return false;
        
    }
    
    void switchOFF(int i, int j, int n){
        if(i < 0 || j < 0 || i >= n || j >= n) return;
        
        if(litLamps.find({i, j}) == litLamps.end()) return;
        
        litLamps.erase({i, j});
        
        row[i]--;
        col[j]--;
        positiveDiag[i + j]--;
        negativeDiag[i - j]--;
        
        return ;
    }
    
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
                
        int N = lamps.size(), M = queries.size();
        vector<int> ans(M, 0);
        
        for(int i = 0; i < N; i++){
            if(litLamps.find({lamps[i][0], lamps[i][1]}) != litLamps.end()) continue;            
            litLamps.insert({lamps[i][0], lamps[i][1]});
            row[lamps[i][0]]++;
            col[lamps[i][1]]++;
            positiveDiag[lamps[i][0] + lamps[i][1]]++;
            negativeDiag[lamps[i][0] - lamps[i][1]]++;
        }
        
        for(int i = 0; i < M; i++){
            
            int a = queries[i][0], b = queries[i][1];
            
            if(isLit(a, b)){
                ans[i] = 1;
            }
            
            switchOFF(a, b, n);
            switchOFF(a, b + 1, n);
            switchOFF(a + 1, b + 1, n);
            switchOFF(a + 1, b, n);
            switchOFF(a, b - 1, n);
            switchOFF(a - 1, b - 1, n);
            switchOFF(a - 1, b, n);
            switchOFF(a - 1, b + 1, n);
            switchOFF(a + 1, b - 1, n);
            
        }
        
        return ans;
        
    }
};