class Solution {
    int isPossible(int mid,vector<int>& positions,int m){
        int count=1;
        int prev=positions[0];
        
        for(int i=1;i<positions.size();i++){
            if(positions[i]-prev>=mid){
                                        count++;
prev=positions[i];
            }
        }
        
        if(count>=m)
            return 1;
        return 0;
    }
    
public:
    int maxDistance(vector<int>& positions, int m) {
        sort(positions.begin(),positions.end());
        
        int n=positions.size();
        int l=1;
        int h=positions[n-1]-positions[0];
        int ans=0;
        
        while(l<=h){
            int mid=(h+l)/2;
            
            if(isPossible(mid,positions,m)){
                ans=max(ans,mid);
                l=mid+1;
            }
            
            else
                h=mid-1;
        }
        return ans;
    }
};