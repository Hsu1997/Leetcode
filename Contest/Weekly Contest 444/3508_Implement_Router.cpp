#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Router {
public:
    struct pair_hash{
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    int n;
    unordered_set<pair<int,int>, pair_hash> s;
    int last_time = -1;
    queue<pair<int, pair<int,int>>> mem;
    unordered_map<int,vector<int>> label_destination;

    Router(int memoryLimit) {
        n = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if (timestamp == last_time){
            if (s.find({source, destination}) != s.end()) return false;
        }
        else{
            last_time = timestamp;
            s.clear();
        }
        s.insert({source, destination});
        
        if (mem.size() == n) forwardPacket();
        mem.push({timestamp, {source, destination}});
        label_destination[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (mem.empty()) return {};
        auto [time, detail] = mem.front();
        mem.pop();
        auto [from, to] = detail;
        if (time == last_time) s.erase({from, to});
        if (!label_destination[to].empty() && label_destination[to].front() == time) {
            label_destination[to].erase(label_destination[to].begin());
        }
        return {from, to, time};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        vector<int>& v = label_destination[destination];
        auto u = upper_bound(v.begin(), v.end(), endTime);
        auto l = lower_bound(v.begin(), v.end(), startTime);
        return u - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

int main(){
    Router* S = new Router(3);
    cout << S->addPacket(1,4,90) << endl;
    cout << S->addPacket(2,5,90) << endl;
    cout << S->addPacket(1,4,90) << endl;
    cout << S->addPacket(3,5,95) << endl;
    cout << S->addPacket(4,5,105) << endl;
    for (int i : S->forwardPacket()) cout << i << " ";
    cout << endl;
    cout << S->addPacket(5,2,110) << endl;
    cout << S->getCount(5, 100, 110) << endl;

    // Router* S = new Router(2);
    // cout << S->addPacket(7,4,90) << endl;
    // for (int i : S->forwardPacket()) cout << i << " ";
    // cout << endl;
    // for (int i : S->forwardPacket()) cout << i << " ";
    // cout << endl;

    return 0;
}