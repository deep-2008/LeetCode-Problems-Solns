class MyHashMap {
      int v[1000002];
public:
    MyHashMap() {
        long long s;
       
        s=1e6+1;
        
       // v.resize(s);
        for(int i=0;i<1000002;i++)
            v[i]=-1;
    }
    
    void put(int key, int value) {
        v[key]=value;
    }
    
    int get(int key) {
        return v[key];
    }
    
    void remove(int key) {
        v[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */