class UndergroundSystem {
private:
    unordered_map<int, pair<string,double>> records;
    unordered_map<string ,pair<double,int>> trips;
public:
    UndergroundSystem() {
        this->records = unordered_map<int, pair<string,double>>();
        this->trips = unordered_map<string, pair<double,int>>();
    }
    
    void checkIn(int id, string stationName, int t) {
        records[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto record = records[id];
        records.erase(id);
        string trip_name = record.first + "->" + stationName;
        trips[trip_name].first += t - record.second;
        trips[trip_name].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string trip_name = startStation + "->" + endStation;
        auto trip = trips[trip_name];
        return trip.first / trip.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */