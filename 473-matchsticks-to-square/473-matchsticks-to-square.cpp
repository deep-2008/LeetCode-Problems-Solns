// class Solution {
//     bool solve(vector<int>& nums,int ind,int &side1,int &side2,int &side3,int &side4,int eachSide){
//         if(ind==nums.size()){
//             if(side1==0 && side2==0 && side3==0 && side4==0)
//                 return true;
//             return false;
//         }
        
//         if(nums[ind]<=side1){
//             side1-=nums[ind];
//             if(solve(nums,ind+1,side1,side2,side3,side4,eachSide))
//                 return true;
//             side1+=nums[ind];
//         }
        
//         if(nums[ind]<=side2){
//             side2-=nums[ind];
//             if(solve(nums,ind+1,side1,side2,side3,side4,eachSide))
//                 return true;
//             side2+=nums[ind];
//         }
        
//         if(nums[ind]<=side3){
//             side3-=nums[ind];
//             if(solve(nums,ind+1,side1,side2,side3,side4,eachSide))
//                 return true;
//             side3+=nums[ind];
//         }
        
//         if(nums[ind]<=side4){
//             side4-=nums[ind];
//             if(solve(nums,ind+1,side1,side2,side3,side4,eachSide))
//                 return true;
//             side4+=nums[ind];
//         }
        
//         return false;
//     }
    
// public:
//     bool makesquare(vector<int>& matchsticks) {
//         int n=matchsticks.size();
//         int sum=0;
        
//         for(auto i:matchsticks)
//             sum+=i;
        
//         if(sum%4!=0)
//             return false;
        
//         int eachSide=sum/4;
//         sort(matchsticks.begin(),matchsticks.end());
//         int side1=eachSide,side2=eachSide,side3=eachSide,side4=eachSide;
        
//         return solve(matchsticks,0,side1,side2,side3,side4,eachSide);
//     }
// };





class Solution {
	// a,b,c,d are four sides of square
    int a,b,c,d;
    bool fun(vector<int>& matchsticks,int i){
        //Base Case
        if(i==matchsticks.size()){
            if(a==0 && b==0 && c==0 && d==0) return true;
            else return false;
        }
        
		//Now we will explore for all side for given index
		
		// if matchstick size is less than side(a or b or c or d)  size , then in that case we will not explore that because that will cause negative side which is not possible
        if(matchsticks[i]<=a){
            a-=matchsticks[i];
            if(fun(matchsticks,i+1)) return true;
            a+=matchsticks[i];      // backtrack step
        }
        
        if(matchsticks[i]<=b){
            b-=matchsticks[i];
            if(fun(matchsticks,i+1)) return true;
            b+=matchsticks[i];        // backtrack step                    
        }
        
        if(matchsticks[i]<=c){
            c-=matchsticks[i];
            if(fun(matchsticks,i+1)) return true;
            c+=matchsticks[i];         // backtrack step
        }
        
        if(matchsticks[i]<=d){
            d-=matchsticks[i];
            if(fun(matchsticks,i+1)) return true;
            d+=matchsticks[i];         // backtrack step
        }
		
		//If none of the explored option retuen true then  we have to return false
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
		//  if less than four number present in array , then we can not make square
        if(matchsticks.size()<4) return false;
        
		// if sum of all number of array is not divisible by 4 , then we can not create a square
		int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
        if(sum % 4 != 0) return false;
        
		int sizeSum=sum/4;
        a=sizeSum,b=sizeSum,c=sizeSum,d=sizeSum;
        
		// here we sort our array in reverse order to escape more cases
		sort(matchsticks.rbegin(), matchsticks.rend());
        
		return fun(matchsticks,0);
    }
};