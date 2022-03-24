class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(),people.end());
        
        int n=people.size();
        int l=0,r=n-1,count=0;
        if(n==1)
            return 1;
        
        while(l<=r){
            if(people[l] + people[r] <=limit){
                count++;
                l++;
                r--;
            }
            
            else{
                count++;
                r--;
            }
        }
       // if(n==2)
            return count;
       // return count+1;
    }
};