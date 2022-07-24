class FoodRatings {
    unordered_map<string,set<pair<int,string>>> mp;
    unordered_map<string,string> temp;
    unordered_map<string,int> rat;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        
        for(int i=0;i<n;i++){
            mp[cuisines[i]].insert({-ratings[i],foods[i]});
            temp[foods[i]]=cuisines[i];
            rat[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cui=temp[food];
        int rats=rat[food];
        mp[cui].erase({-rats,food});
        mp[cui].insert({-newRating,food});
        rat[food]=newRating;

    }
    
    string highestRated(string cuisine) {
//         int n=mp[cuisine].size();
//         string ans="",t="";
//         int c=0;
//         for(auto it:mp[cuisine]){
//             if(it.first>c){
//                 ans=it.second;
//                 c=it.first;
//             }
            
//             // if(c==it.first)
//             //     return ans;
//         }
//         // auto it=mp[cuisine];
        
        
//         return ans;
        
        return begin(mp[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */