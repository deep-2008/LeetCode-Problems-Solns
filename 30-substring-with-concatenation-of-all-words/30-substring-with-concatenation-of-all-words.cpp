// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         int n=s.size();
//         int len=words[0].size();
//         vector<int> ans;
        
//         map<string,int> mp;
        
//         for(int i=0;i<words.size();i++){
//             mp[words[i]]++;
//         }
//         // cout<<mp[words[0]];
//         for(int i=0;i<n-len+1;i++){
//             int curr=i;
//             int start=i;
            
//             map<string,int> copy(mp);
            
//             while(curr+len<n+1){
//                 string temp=s.substr(curr,len);
//                 // cout<<temp<<" ";
                
//                 if(copy.find(temp)!=copy.end()){
//                     copy[temp]--;
//                     if(copy[temp]==0)
//                         copy.erase(temp);
//                     if(copy.size()==0){
//                         ans.push_back(start);
//                         break;
//                     }
//                     // cout<<copy.size()<<" ";
//                      curr+=len;
//                 }
                
//                 else
//                     break;
                
               
//             }
//                         // cout<<copy[words[0]]<<" ";

//         }
        
//         return ans;
//     }
// };




class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int n=words.size();
        int m=words[0].size();
        int total=n*m;
        if(s.size()<total){
            return ans;
        }
        for(int i=0;i<=s.size()-total;i++){
            unordered_map<string,int>mp;
            
            for(int j=0;j<words.size();j++){
                mp[words[j]]++;
            }
            int k;
            for(k=0;k<n;k++){
                
                string temp=s.substr(i+k*m,m);
                // cout<<temp<<" "<<i<<endl;
                if(mp.count(temp)==0){
                    break;
                }
                else{
                    if(mp[temp]!=0){
                        mp[temp]--;
                    }
                    else{
                        break;
                    }
                }
            }
            if(k==n){
                ans.push_back(i);
            }
            
        }
        return ans ;
    }
};