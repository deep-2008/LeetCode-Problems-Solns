class Solution {
public:
    // creating int to roman map.
    unordered_map<int,char>itor={
        {1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'}
    };
    // reverse the string.
    void reverse(string &s)
    {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;j--;
        }
    }
    // main function.
    string intToRoman(int num) {
        
        string res="";
        //Multiplier to determine once,tens... places
        int mul=1;
        while(num)
        {
            int x=num%10; //last digit
            num/=10; //removing last digit from num.
            if(x==0) //if zero then move to next digit (with increasing multiplier).
            {
                mul*=10;
                continue;
            }
            // we have two cases 4 and 9 then make b=5 || 10.
            int b=-1;
            if(x==4)
                b=5;
            else if(x==9)
                b=10;
            
            if(b==-1) //if last digit is not 4||9 then simply add I. for 3= III
            {
                while(x)
                {
                    if(x==5)
                    {
                        res+=itor[5*mul];
                        x-=5;
                    }
                    else
                    {
                        res+=itor[1*mul];
                        x-=1;
                    }
                }
            }
            else // if(last digit is 4||9) then add IV or IX to res.
            {
                res+=itor[b*mul];
                res+=itor[1*mul];
            }
            mul*=10;
        }
        //we traversed from lsb to msb so reverse the string.
        reverse(res);
        return res;
        // remember if 4 comes then we add VI to res so that reverse will be IV.
    }
};