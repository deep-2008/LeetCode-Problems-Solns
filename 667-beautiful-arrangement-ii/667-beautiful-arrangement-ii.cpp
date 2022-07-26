class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> store;
        
        // for(int i=0;i<n;i++)
        //     store.push_back(i+1);
        
        // if(k<=1)
        //     return store;
        
//         int temp=1;
//        for(int i=1;i<n-1;i++){
//            if(temp==k)
//                break;
           
//            int l=i,h=n-1;
//            while(l<h){
//                swap(store[l],store[h]);
//            }temp++;
//        }
        
        int lo=1,hi=n,f=0,i=1;
        store.push_back(lo);
        lo++;
        
        while(k>1){
           store.push_back(hi);
            hi--;
            k--;
            f=1;
            i++;
            
            if(k>1){
                store.push_back(lo);
                lo++;
                k--;
                f=0;
                i++;
            }
        }
        
        // if(f==1)
        while(i<n){
           if(f==1){
               store.push_back(hi);
               hi--;i++;
           } 
            
            else{
                store.push_back(lo);
                lo++;i++;
            }
        }
        
        return store;
    }
};