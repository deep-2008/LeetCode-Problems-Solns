class Solution {
    int check(vector<int>& a,vector<int>& b){
        int csum=0,osum=0,sum=0;
        
        sum=accumulate(a.begin(),a.end(),0);
        
        for(int i=0;i<a.size();i++){
            csum+= (b[i]-a[i]);
            
            if(csum<0)
                csum=0;
            osum=max(osum,csum);
        }
        
        return sum+osum;
    }
    
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        return max(check(nums1,nums2),check(nums2,nums1));
    }
};