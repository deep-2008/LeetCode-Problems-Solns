class Solution {
public:
    int maxArea(vector<int>& height) {
       int csum=0,ans=0;
        int n=height.size();
        int i=0,j=n-1;
        
       /* for(int i=0;i<n-1;i++){
            for(int j=n-1;j>i;j--){
                csum= (min(height[i],height[j])) * (abs(j-i));
                ans = max(ans,csum);
            }
        }*/
        while(i<j){
            if(height[i]<height[j]){
                csum = height[i] * (j-i);
                i++;
            }
            
            else{
                csum=height[j] *(j-i);
                j--;
            }
            ans=max(ans,csum);
        }
        
        return ans;
    }
};