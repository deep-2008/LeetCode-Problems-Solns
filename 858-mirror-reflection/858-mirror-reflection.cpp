class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g=__gcd(p,q);
        p=p/g;
        q=q/g;
        
        if(p==q)
            return 1;
        
        if(p%2==0)
            return 2;
        else{
            if(q%2==0)
                return 0;
            else
                return 1;
        }
    }
};