class Solution {
    bool solve(vector<int>& nums,int ind,int &side1,int &side2,int &side3,int &side4,int eachSide){
        if(ind==nums.size()){
            if(side1==0 && side2==0 && side3==0 && side4==0)
                return true;
            return false;
        }
        
        if(nums[ind]<=side1){
            side1-=nums[ind];
            if(solve(nums,ind+1,side1,side2,side3,side4,eachSide))
                return true;
            side1+=nums[ind];
        }
        
        if(nums[ind]<=side2){
            side2-=nums[ind];
            if(solve(nums,ind+1,side1,side2,side3,side4,eachSide))
                return true;
            side2+=nums[ind];
        }
        
        if(nums[ind]<=side3){
            side3-=nums[ind];
            if(solve(nums,ind+1,side1,side2,side3,side4,eachSide))
                return true;
            side3+=nums[ind];
        }
        
        if(nums[ind]<=side4){
            side4-=nums[ind];
            if(solve(nums,ind+1,side1,side2,side3,side4,eachSide))
                return true;
            side4+=nums[ind];
        }
        
        return false;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        int sum=0;
        
        for(auto i:matchsticks)
            sum+=i;
        
        if(sum%4!=0)
            return false;
        
        int eachSide=sum/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        int side1=eachSide,side2=eachSide,side3=eachSide,side4=eachSide;
        
        return solve(matchsticks,0,side1,side2,side3,side4,eachSide);
    }
};





