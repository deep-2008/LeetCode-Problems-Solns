// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
unordered_map<string,int> mp;
int mod=1003;
int solve(string s,int i,int j,bool isTrue){
    if(i>j)
    return false;
    
    if(i==j){
        if(isTrue==true)
        return s[i]=='T';
        else
        return s[i]=='F';
    }
    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
    
    if(mp.find(temp)!=mp.end())
    return mp[temp];
    
    
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2){
        int lt=solve(s,i,k-1,true);
        int lf=solve(s,i,k-1,false);
        int rt=solve(s,k+1,j,true);
        int rf=solve(s,k+1,j,false);
        
        if(s[k]=='&'){
            if(isTrue==true)
            ans+=(lt*rt);
            else
            ans+=(lt*rf)+(lf*rt)+(rf*lf);
        }
        
        else if(s[k]=='^'){
            if(isTrue==true)
            ans+=(lf*rt)+(lt*rf);
            else
            ans+=(lt*rt)+(lf*rf);
        }
        
        else if(s[k]=='|'){
            if(isTrue==true)
            ans+=(lt*rt)+(lf*rt)+(lt*rf);
            else
            ans+=(lf*rf);
        }
    }
    return mp[temp]=ans%mod;
}
    int countWays(int N, string S){
        // code here
        mp.clear();
        return solve(S,0,N-1,true)%mod;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends