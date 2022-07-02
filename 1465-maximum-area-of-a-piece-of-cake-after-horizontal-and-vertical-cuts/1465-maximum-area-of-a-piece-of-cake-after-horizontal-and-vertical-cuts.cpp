#define mod 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
         horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
                

        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
       long long int ans=0;
        long long int max_hc=0,max_vc=0;
        
        for(int i=0;i<horizontalCuts.size()-1;i++){
            max_hc=max(max_hc,(1ll)*(horizontalCuts[i+1]-horizontalCuts[i]));
        }
        
        for(int i=0;i<verticalCuts.size()-1;i++){
            max_vc=max(max_vc,(1ll)*(verticalCuts[i+1]-verticalCuts[i]));
        }
        
        // ans = ((max_hc%mod)*(max_vc%mod))%mod;
        max_hc=max_hc%mod;
        max_vc=max_vc%mod;
        ans=(max_hc * max_vc)%mod;
        int ans1=ans;
        return ans1;
    }
};