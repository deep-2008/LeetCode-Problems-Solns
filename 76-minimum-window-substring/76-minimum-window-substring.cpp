// // class Solution {
// // public:
// //     string minWindow(string s, string t) {
// //         int m=s.size();
// //         int n=t.size();
// //         vector<string> ans;
// //         string result="";
// //         int mini=INT_MAX;
        
// //         int sp=0,ep=0;
// //         map<char,int> mp;
        
// //         for(int i=0;i<n;i++)
// //             mp[t[i]]++;
        
// //         while(sp<m-n+1){
// //             ep=sp;
// //             map<char,int> copy(mp);
            
// //             if(copy.find(s[sp])==copy.end()){
// //                 sp++;
                
// //             }
            
// //             else{
// //                 string temp;
// //             while(ep<m){
// //                 temp.push_back(s[ep]);
// //                 if(copy.find(s[ep])!=copy.end()){
// //                     copy[s[ep]]--;
// //                     if(copy[s[ep]]==0)
// //                         copy.erase(s[ep]);
                    
// //                     if(copy.size()==0){
// //                         if(temp.size()<mini){
// //                             result=temp;
// //                             mini=temp.size();
// //                         }
// //                         // ans.push_back(temp);
// //                         break;
// //                     }
// //                 }
// //                 ep++;
// //               }
// //                 sp++;
// //             }
            
// //         }
        
// //         // for(int i=0;i<ans.size();i++){
// //         //     // cout<<ans[i]<<" ";
// //         //     if(ans[i].size()<size){
// //         //         result=ans[i];
// //         //         size=ans[i].size();
// //         //     }
// //         // }
        
// //         return result;
// //     }
// // };



 class Solution {
 public:
//     string minWindow(string s, string t) {
//         int n = s.length(), m = t.length();
//         if(n<m) return "";
//         unordered_map<char,int> mp;
//         for(char &ele:t){
//             mp[ele]++;
//         }
//         int count = mp.size();
//         int i=0,j=0,ans=INT_MAX;
//         string res="";
//         while(j<n){
//             if(mp.find(s[j])!=mp.end()){
//                 mp[s[j]]--;
//                 if(mp[s[j]]==0){
//                     count--;
//                 }
//             }
//             while(count==0){
//                 if(j-i+1<ans){
//                     ans=j-i+1;
//                     res=s.substr(i,j-i+1);
//                 }
//                 if(mp.find(s[i])!=mp.end()){
//                     mp[s[i]]++;
//                     if(mp[s[i]]>0){
//                         count++;
//                     }
//                 }
//                 i++;
//             }
//             j++;
//         }
//         return res;
//     }
// };

string minWindow(string s, string t) {
        int m=s.size(), n=t.size();
        unordered_map<char, int> mp;
        
        int ans = INT_MAX; 
        int start = 0; 
        
        for(auto x:t)
            mp[x]++;
        
        int count = mp.size();
        
        int i = 0, j = 0;

        while (j < s.length()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;

            if (count == 0) {
                while (count == 0) {
                    if (ans > j - i + 1) {
                        ans = j - i + 1;
                        start = i;
                    }
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                        count++;

                    i++;
                }
            }
            j++;
        }
        if (ans != INT_MAX)
            return s.substr(start, ans);
        else
            return "";
    }};