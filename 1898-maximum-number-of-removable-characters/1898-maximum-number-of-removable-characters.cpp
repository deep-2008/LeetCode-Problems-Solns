class Solution {
    bool isSubsequence(string s,string p){
        int i=0,j=0;
        
        while(i<s.size() && j<p.size()){
            if(s[i]==p[j]){
                i++;j++;
            }
            
            else
                i++;
        }
        
        if(j==p.size() && i<=s.size())
            return true;
        
        return false;
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n=s.size();
        int m=p.size();
        int ans=0,size=removable.size();
        int l=0,h=size;
        
        string copy=s;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            for(int i=0;i<mid;i++){
                s[removable[i]]='#';
            }
            
            if(isSubsequence(s,p)){
                ans=max(ans,mid);
                l=mid+1;
            }
            
            else{
                 for(int i=0;i<mid;i++){
                s[removable[i]] = copy[removable[i]];
            }
                h=mid-1;
                
            }
        }
        
        
        
        return ans;
    }
};