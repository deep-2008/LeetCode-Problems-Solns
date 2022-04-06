class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int csum=values[0],osum=0,n=values.size(),i=0,j=n-1;
        
      /*  while(i<j){
            csum=values[i]+values[j]+i-j;
            osum=max(osum,csum);
            
            if(values[i]<values[j])
                i++;
            else if(values[i]>values[j])
                j--;
            else{
                if(values[i+1]<values[j-1])
                    i++;
                else
                    j--;
            }
        }*/
        
        for(int k=1;k<n;k++){
           osum=max(osum,values[k]-k+csum);
            csum=max(csum,values[k]+k);
        }
        
        return osum;
    }
};