class Solution {
public:
    int brokenCalc(int startValue, int target) {

        int count = 0;
        
        while(startValue < target ){
          //  if(target==startValue)
            //    break;
            count++;
            if(target%2==0){
                target=target/2;
              //  count++;
            }
            else{
                target+=1;
                //count++;
            }
            
                
        }
        return count+startValue-target;
    }
};