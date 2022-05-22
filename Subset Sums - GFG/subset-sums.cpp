// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
#define vii vector<vector<int>>
#define vi vector<int>

void comb(vi &arr, vi &ans,int i,int &sum){
    if(i==arr.size()){
        ans.push_back(sum);
        return;
    }
    
    sum+=arr[i];
    comb(arr,ans,i+1,sum);
    
    sum-=arr[i];
    comb(arr,ans,i+1,sum);
}


    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vi ans;
        
        int sum=0;
        
        comb(arr,ans,0,sum);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends