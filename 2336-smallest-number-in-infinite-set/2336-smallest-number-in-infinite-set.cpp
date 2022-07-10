class SmallestInfiniteSet {
    priority_queue<int,vector<int>,greater<int>> minh;
    unordered_map<int,int> mp;
    // int t;
    // set<int> st;
public:
    SmallestInfiniteSet() {
        for(int i=1;i<=1002;i++){
            minh.push(i);
            mp[i]=1;
        }
        // t=1;
        // for(int i=1;i<=1000;i++)
            // st.insert(i);
    }
    
    int popSmallest() {
        int x=minh.top();
        minh.pop();
        mp.erase(x);
        
        return x;
        
//         if(minh.size()==0)
//             return t++;
        
//         if(minh.top()<t){
//             int a=minh.top();
//             minh.pop();
//             return a;
//         }
        
//         else
//             return t++;
        
        // auto it=st.begin();
        // int temp=*it;
        // st.erase(it);
        // return temp;
    }
    
    void addBack(int num) {
        if(mp.find(num)==mp.end()){
            mp[num]=1;
            minh.push(num);
        }
        
        // if(num<t){
        //     minh.push(num);
        // }
        
        // if(st.find(num)==st.end())
            // st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */