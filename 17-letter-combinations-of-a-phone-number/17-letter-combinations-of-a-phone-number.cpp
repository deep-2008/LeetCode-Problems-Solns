class Solution {
    void solve(string digits,string mp[],vector<string>& ans,string ds,int ind){
        if(ind==digits.size()){
            ans.push_back(ds);
            return;
        }
        
        int val=digits[ind]-'0';
        string letters=mp[val];
        
        for(int i=0;i<letters.size();i++){
            ds.push_back(letters[i]);
            solve(digits,mp,ans,ds,ind+1);
            ds.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        vector<string> ans;
        string ds;
        if(digits.size()==0)
            return ans;
        
        solve(digits,mp,ans,ds,0);
        return ans;
    }
};