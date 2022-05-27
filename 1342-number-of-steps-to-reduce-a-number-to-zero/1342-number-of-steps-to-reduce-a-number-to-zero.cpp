class Solution {
public:
    int numberOfSteps(int n) {
        int count=0;
        /*while(n!=0){
            if(n%2==0)
                n/=2;
            else
                n-=1;
            count++;
        }*/
        
        while(n!=0){
            if(!(n&1))
                n=n>>1;
            else
                n--;
            count++;
        }
        return count;
    }
};