class UndergroundSystem {
    
private:
    
    unordered_map<int,pair<string,int>> customer;
    unordered_map<string,vector<int>> transit;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customer[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto res = customer[id];
        string startStation = res.first;
        int s = res.second;
        
        string key = startStation + "-" + stationName;
        
        transit[key].push_back(t-s);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "-" + endStation;
        vector<int> val = transit[key];
        
        double sum = accumulate(val.begin(),val.end(),0);
        
        return sum/val.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */