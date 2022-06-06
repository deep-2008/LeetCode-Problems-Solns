class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,h=height.size()-1;
        int ans=0;
        while(l<h){
            int csum=(h-l)* (min(height[l],height[h]));
            ans=max(ans,csum);
            
            if(height[l] < height[h])
                l++;
            
            else if(height[l] > height[h])
                h--;
            
            else{
                if(height[l+1] < height[h-1])
                    l++;
                else
                    h--;
            }
        }
        
        return ans;
    }
};


