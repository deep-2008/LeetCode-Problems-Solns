class Solution {
//     bool compare(unordered_map<char,int> mp,unordered_map<char,int> ms){
        
//        if(mp.size() != ms.size())
//            return false;
        
//         for(auto  i=mp.begin(),j=ms.begin();i!=mp.end();i++,j++){
//             if(*i != *j)
//                 return false;
//         }
        
//         return true;
//     }
    
public:
    vector<int> findAnagrams(string s, string p) {
//         int k=p.size();
//         int size=s.size();
        
//         int i=0,j=0,start=0;
//         vector<int> ans;
        
//         unordered_map<char,int> mp,ms;
//         for(int i=0;i<k;i++){
//             mp[p[i]]++;
//             ms[s[i]]++;
//         }
       
//         j=k;
//         while(j<size){
            
            
//             if(compare(mp,ms)==true){
//                 ans.push_back(i);           
//             }
//              ms[s[i]]--;
//              ms[s[j]]++;
//              i++;j++;
          
//         }
        
//           if(compare(mp,ms)==true){
//                 ans.push_back(i);           
//             }
        
//         return ans;
        
         int n = s.size();
        int k = p.size();
        map<char,int>seen;
        for(int i = 0 ; i < 26 ; i++)
        {
            char ch = (char)(97+i);
            seen[ch] = (i+1)*(i+1)*(i+1);
        }
        int val = 0;
        for(int i = 0 ; i < k ; i++)
        {
            val+=seen[p[i]];
        }
        vector<int>ans;
        int cnt = 0;
        int i = 0, j  = 0;
        while(j<n)
        {
            cnt+=seen[s[j]];
            if(j-i+1==k)
            {
                if(cnt==val)
                {
                    ans.push_back(i);
                    
                }
                else
                {
                    
                }
                cnt-=seen[s[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};