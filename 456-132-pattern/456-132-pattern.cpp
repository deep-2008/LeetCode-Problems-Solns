class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return false;
      /*  for(int j=1;j<n-1;j++){
            int i=0;
            while(i<j){
                if(nums[i]<nums[j]){
                    int k=j+1;
                    while(k<n){
                        if(nums[k]<nums[j] && nums[k]>nums[i])
                            return true;
                        else
                            k++;
                    }
                }
                else
                    i++;
            }
        }*/
        
       /* for(int i=0,j=1;i<n-2,j<n-1;i++,j++){
            int k=j+1;
            if(nums[i]<nums[j]){ 
            while(k<n){
                if(nums[k]<nums[j] && nums[k]>nums[i])
                    return true;
                else
                    k++;
            }}
        }*/
        
       
          stack<int>s;
        
        int c=INT_MIN;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<c)
            {
                return true;
            }
            
            while(s.size()!=0 && s.top()<nums[i])
            {
                c=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        
        //return false;
        
        return false;
    }
};