/*class UndergroundSystem {
    
public:
    map<double,pair<string,double>> entry;
    map<pair<string,string>,double> outdata;
    UndergroundSystem() {
       entry.clear();
       outdata.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        entry[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        for(auto it=entry.begin();it!=entry.end();it++){
            int x=it->first;
            if(x==id){
                double temp= it->second.second;
                double rt=t-temp;
               // outdata.push({it.second.first,stationName},rt);
                outdata[{entry[id].first,stationName}] = rt;
                break;
            }
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
       vector<double> ans;
        int count=0;
         for(auto it=outdata.begin();it!=outdata.end();it++){
             string s1=it->first.first;
             string s2=it->first.second;
             
             if(s1==startStation && s2==endStation){
                 ans.push_back(it->second);
                 count++;
             }
         }
        double sum=0;
        for(int i=0;i<ans.size();i++)
            sum+=ans[i];
       // cout<<sum<<endl;
        //double r=(0.0+sum)/(0.0+count);
        return sum/count;
        
        }
};*/

class UndergroundSystem {
public:
    map<double,pair<string,double>> customer;
	//customer is storing customer id as key and stationname and time as value
    map<pair<string, string>, pair<double, double>> total;
	//total is storing startstation and endstation as key and totaltime and count as value
    UndergroundSystem() {
        customer.clear();
        total.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        customer[id]={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        total[{customer[id].first, stationName}]={total[{customer[id].first, stationName}].first+(t-customer[id].second),total[{customer[id].first, stationName}].second+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return total[{startStation,endStation}].first/total[{startStation,endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */