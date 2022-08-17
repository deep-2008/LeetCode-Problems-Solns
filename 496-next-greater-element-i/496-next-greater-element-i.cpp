class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        map<int,int> mp;
        stack<int> st;
        
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[i]>st.top())
                st.pop();
            
            if(st.size()==0)
                mp[nums2[i]]=-1;
            
            else
            mp[nums2[i]]=st.top();
            
            st.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++){
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};