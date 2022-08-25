class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> rnote,mag;
        
        for(auto i:ransomNote)
            rnote[i]++;
        
        for(auto i:magazine)
            mag[i]++;
        
        for(int i=0;i<ransomNote.size();i++){
            if(mag.find(ransomNote[i])!=mag.end()){
                mag[ransomNote[i]]--;
                if(mag[ransomNote[i]]==0)
                    mag.erase(ransomNote[i]);
            }
            else
                return false;
        }
        return true;
    }
};