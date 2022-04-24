#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> in_out_record;
    unordered_map<string, pair<int, int>> total_status;

    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        in_out_record[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> temp = in_out_record[id];
        in_out_record.erase(id);
        string start = temp.first;
        string end = stationName;
        int time = t - temp.second;
        string route = start + ',' + end;

        total_status[route].first += time;
        total_status[route].second++;
        // cout << "(" << total_status[route].first << "," << total_status[route].second << ")" << endl;
        return;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + ',' + endStation;
        // cout << "(" << total_status[route].first << "," << total_status[route].second << ")" << endl;
        cout << (double)total_status[route].first / total_status[route].second << endl;
        return (double)total_status[route].first / total_status[route].second;
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
    undergroundSystem->getAverageTime("Paradise", "Cambridge"); // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
    undergroundSystem->getAverageTime("Leyton", "Waterloo");    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
    undergroundSystem->checkIn(10, "Leyton", 24);
    undergroundSystem->getAverageTime("Leyton", "Waterloo");    // return 11.00000
    undergroundSystem->checkOut(10, "Waterloo", 38);  // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
    undergroundSystem->getAverageTime("Leyton", "Waterloo");    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12

    return 0;
}