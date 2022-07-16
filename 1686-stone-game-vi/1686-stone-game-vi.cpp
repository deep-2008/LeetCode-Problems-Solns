class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        // return 0;
        int n=aliceValues.size();
        priority_queue<pair<int,int>> alice;
         // priority_queue<pair<int,int>> bob;
        
        for(int i=0;i<n;i++){
            alice.push({aliceValues[i]+bobValues[i],i});
            // bob.push({bobValues[i],i});
        }
        
        int count=0,asum=0,bsum=0,f=0;
        
        while(alice.size()>0){
            auto node=alice.top();
            alice.pop();
           if(f==0){
               // auto node=alice.top();
               // while(aliceValues[alice.top().second]==0)
                   // alice.pop();
               
               f=1;
               // auto node=alice.top();
               // alice.pop();
               asum+=aliceValues[node.second];
               // aliceValues[node.second]=0;
               // bobValues[node.second]=0;
           } 
            
             else if(f==1){
               // auto node=alice.top();
               // while(aliceValues[alice.top().second]==0)
                   // alice.pop();
               
               f=0;
               // auto node=alice.top();
               // alice.pop();
               bsum+=bobValues[node.second];
               // aliceValues[node.second]=0;
               // bobValues[node.second]=0;
           } 
        }
        
        if(asum>bsum)
            return 1;
        else if(asum<bsum)
            return -1;
        else
            return 0;
    }
};