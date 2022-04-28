class Solution {
public:
    bool help(int i,int j,int mid,int n,int m,vector<vector<int>>&h, int v[100][100]){
        if(i==n-1 && j==m-1)
            return true;
        v[i][j]=1;
        bool op=false;
        
        if(i>0 && v[i-1][j]==0 && abs(h[i][j]-h[i-1][j])<=mid)
            op=op||help(i-1,j,mid,n,m,h,v);
         
        if(j>0 && v[i][j-1]==0 && abs(h[i][j]-h[i][j-1])<=mid)
            op=op||help(i,j-1,mid,n,m,h,v);
         
        if(i<n-1 && v[i+1][j]==0 && abs(h[i][j]-h[i+1][j])<=mid)
            op=op||help(i+1,j,mid,n,m,h,v);
         
        if(j<m-1 && v[i][j+1]==0 && abs(h[i][j]-h[i][j+1])<=mid)
            op=op||help(i,j+1,mid,n,m,h,v);
        
        return op;
    }
    int minimumEffortPath(vector<vector<int>>& h) {
        int s=0,e=INT_MAX,ans=INT_MAX,n=h.size(),m=h[0].size();
       
        while(s<=e){
             int v[100][100];
        memset(v,0,sizeof(v));
            int mid=s+(e-s)/2;
            
            if(help(0,0,mid,n,m,h,v)){
                ans=min(ans,mid);
                e=mid-1;
            }
            else
                s=mid+1;
        }
        
        return ans;
        
    }
};