class Solution {
public:
bool stoneGameIX(vector<int>& stones) {
int count1=0;
int count2=0;
int count0=0;
for(int i=0;i<stones.size();i++){
if(stones[i]%3==1){
count1++;
}
else if(stones[i]%3==2){
count2++;
}
else{
count0++;
}
}
if(count1==0 && count2==0){
return false;
}
if(count1==0 || count2==0){
if(count1==1|| count2==1 || count1==2 || count2==2){
return false;
}
if(count0%2){
return true;
}
else{
return false;
}
}
if(count1==count2){
if(count0%2){
return false;
}
else{
return true;
}
}
else{
if(count0%2){
int min_val=min(count1,count2);
int max_val=max(count1,count2);
if(max_val-2<=min_val){
return false;
}
else{
return true;
}
}
else{
return true;
}
}
}
};