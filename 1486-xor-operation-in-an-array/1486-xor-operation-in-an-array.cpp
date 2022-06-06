class Solution {
public:
    int xorOperation(int n, int start) {
        
        int i=0;
        int xor1=0;
        
        while(i<n){
            xor1 = xor1 ^ (start+(2*i));
            i++;
        }
        
        return xor1;
    }
};