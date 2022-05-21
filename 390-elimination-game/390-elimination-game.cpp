class Solution {
public:
    int ans=0;
    void search(int l,int r,int cur,int dir){
        if(l>=r){
            ans=l;
            return;
        }
        
        if(dir==1){
            if(l%cur == r%cur)
                r-=cur/2;
            l+=cur/2;
            search(l,r,cur*2,-1);
        }
        
        else{
            if(l%cur==r%cur)
                l+=cur/2;
            r-=cur/2;
            search(l,r,cur*2,1);
        }
    }
    
    
    int lastRemaining(int n) {
        int l=1,r=n;
        search(l,r,2,1);
        return ans;
    }
};