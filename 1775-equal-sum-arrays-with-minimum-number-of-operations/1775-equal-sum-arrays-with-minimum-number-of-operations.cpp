class Solution {
    void filler( priority_queue<int>& maxh, priority_queue<int,vector<int>,greater<int>>& minh,vector<int>& a,vector<int>& b){
        for(auto i:a)
            maxh.push(i);
        
        for(auto i:b)
            minh.push(i);
    }
    
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
      // return 0;
        
        int s1=0,s2=0,ans=0;
        for(auto i:nums1)
            s1+=i;
        
        for(auto i:nums2)
            s2+=i;
        
        if(s1==s2)
            return 0;
        
        priority_queue<int> maxh;
        priority_queue<int,vector<int>,greater<int>> minh;
        
        if(s1>s2)
            filler(maxh,minh,nums1,nums2);
        else
            filler(maxh,minh,nums2,nums1);
        
        while(s1!=s2){
        int node1=maxh.top();
        int node2=minh.top();
            
            int diff=abs(s1-s2);
            
            int max_diff=max(abs(node1-1),abs(node2-6));
            
            if(max_diff==0)
                return -1;
            
             if(max_diff >= diff){
                ans++;
                return ans;
            }
            
            else{
                ans++;
                if(abs(node1-1) > abs(node2-6)){
                    maxh.pop();
                    if(s1>s2)
                        s1-=abs(node1-1);
                    else
                        s2-=abs(node1-1);
                    maxh.push(1);
                }
                
                else if(abs(node1-1)<abs(node2-6)){
                    minh.pop();
                    if(s1<s2)
                        s1+=abs(node2-6);
                    else
                        s2+=abs(node2-6);
                    minh.push(6);
                }
                else{
                    minh.pop();
                    if(s1<s2)
                        s1+=abs(node2-6);
                    else
                        s2+=abs(node2-6);
                    minh.push(6);
                }
            }
        }
        
        return ans;
        
    }
};