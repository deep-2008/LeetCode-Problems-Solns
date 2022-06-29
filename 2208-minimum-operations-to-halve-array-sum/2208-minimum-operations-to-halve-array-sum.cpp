class Solution {
public:
    int halveArray(vector<int>& nums) {
      
        double sum=0;//accumulate(nums.begin(),nums.end(),0);
        
        double half=0;//(long double)sum/2;
        int ans=0;
        priority_queue< double> maxh;
        
        for(int i=0;i<nums.size();i++){
            maxh.push(( double)nums[i]);
            sum+=(double)nums[i];
        }
        
        half=sum/2;
        
        while(half>0){
           double node=maxh.top();
            maxh.pop();
            
            // if(node/2 <=)
            half-= node/2;
            ans++;
            maxh.push(node/2);
        }
        
        return ans;
    }
};