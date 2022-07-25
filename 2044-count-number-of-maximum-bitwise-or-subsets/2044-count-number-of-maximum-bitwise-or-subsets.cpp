class Solution {
    void allOrSubsets(vector<int>& nums,vector<int>& store,int ind,int sum){
        if(ind==nums.size()){
            store.push_back(sum);
            return;
        }
        
        allOrSubsets(nums,store,ind+1,sum|nums[ind]);
        allOrSubsets(nums,store,ind+1,sum);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> store;
        
        allOrSubsets(nums,store,0,0);
        
        sort(store.begin(),store.end(),greater<int>());
        
        int ans=1,c=store[0];
        // for(auto i:store)
            // cout<<i<<" ";
        for(int i=1;i<store.size();i++){
            if(store[i]<c)
                break;
            ans++;
        }
        return ans;
    }
};