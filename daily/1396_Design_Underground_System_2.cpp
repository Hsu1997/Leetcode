#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>> passenger;
    unordered_map<string, pair<double,double>> travel_time;

    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        passenger[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string travel_path = passenger[id].first + "-" + stationName;
        travel_time[travel_path].first += (t - passenger[id].second);
        travel_time[travel_path].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string travel_path = startStation + "-" + endStation;
        return travel_time[travel_path].first / travel_time[travel_path].second;
    }

    void print(){
        for (auto i : travel_time){
            cout << i.first << " : " << i.second.first << ", " << i.second.second << endl;
        }
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main(){
    UndergroundSystem* undergroundSystem = new UndergroundSystem();
    undergroundSystem->checkIn(45, "Leyton", 3);
    undergroundSystem->checkIn(32, "Paradise", 8);
    undergroundSystem->checkIn(27, "Leyton", 10);
    undergroundSystem->checkOut(45, "Waterloo", 15);  // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
    undergroundSystem->checkOut(27, "Waterloo", 20);  // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
    undergroundSystem->checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
    cout << undergroundSystem->getAverageTime("Paradise", "Cambridge") << endl; // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
    cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << endl;    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
    undergroundSystem->checkIn(10, "Leyton", 24);
    cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << endl;    // return 11.00000
    undergroundSystem->checkOut(10, "Waterloo", 38);  // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
    cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << endl;    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
    // undergroundSystem->print();
    return 0;
}