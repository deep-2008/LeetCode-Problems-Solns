class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       
        unordered_set<string> list;
        
        for(auto i:wordList)
            list.insert(i);
        
        if(list.find(endWord)==list.end())
            return 0;
        
        queue<string> q;
        
        set<string> vis;
        vis.insert(beginWord);
        // unordered_map<string,int> mp;
        // mp[beginWord]=1;
        
        q.push(beginWord);
        
        sort(wordList.begin(),wordList.end()); //For binary search
        
        int level=0;
        
        while(!q.empty()){
            level++;
            int size=q.size();
            
            while(size-- >0){
                string node=q.front();
                q.pop();
                
                if(node == endWord)
                    return level;
                
                for(int i=0;i<node.size();i++){
                    char old=node[i];
                    
                    for(char j='a';j<='z';j++){
                        if(j!=old){
                        node[i]=j;
                        
                        if(list.find(node)!=list.end() && !vis.count(node)){
                            // if(binary_search(wordList.begin(),wordList.end(),node) && !mp[node]){
                            q.push(node);
                          vis.insert(node);
                           list.erase(node);
                               // mp[node]=1;
                        }
                      }
                    }
                    node[i]=old;
                }
            }
        }
        
        return 0;
    }
};