class Solution {
    static bool comp(vector<int>& a,vector<int>& b){
        if(a[1]==b[1])
            return a[0]>b[0];
        return a[1]>b[1];
    }
    
public:
    int maximumUnits(vector<vector<int>>& box, int truckSize) {
        int n=box.size(),ans=0;
        
        sort(box.begin(),box.end(),comp);
        
        // for(auto i:box)
        //     cout<<i[0]<<" "<<i[1]<<" ";
        // cout<<endl;
        
        for(int i=0;i<n;i++){
            if(truckSize==0)
                return ans;
            
            int boxes=box[i][0];
            int units=box[i][1];
            
            if(boxes<=truckSize){
                truckSize-=boxes;
                ans+= (units*boxes);
            }
            
            else{
                int rem=boxes-truckSize;
                ans+=(units*truckSize);
                truckSize-=truckSize;
            }
        }
        return ans;
    }
};