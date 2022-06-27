//#define ll long long
class Solution {
public:
    int minPartitions(string n) {
        //long long int x=stoll(n, nullptr, 10);
        int ans=0;
        
for(int i=0;i<n.size();i++){
    int x=n[i] - '0';
    
    ans=max(ans,x);
}        
        return ans;
    }
};