class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int c=minutesToTest/minutesToDie;
        c+=1;
        int ans=0;
        
        for(int i=0;i<=buckets;i++){
            if(pow(c,i)>=buckets){
                ans=i;
                break;
            }
        }
        
        return ans;
    }
};