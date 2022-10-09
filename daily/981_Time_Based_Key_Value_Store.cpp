#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct node{
    string val;
    int time;
};

class TimeMap {
public:
    unordered_map<string,vector<node>> m;
    TimeMap() {
        // unordered_map<string,vector<node>> m;
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end() || m[key][0].time > timestamp) return "";
        int l = 0;
        int r = m[key].size()-1;
        if (m[key][r].time <= timestamp) return m[key][r].val;
        while(l < r){
            int mid = l + (r-l)/2;
            if (m[key][mid].time == mid) return m[key][mid].val;
            else if (m[key][mid].time < mid) l = mid;
            else r = mid-1;
        }
        return m[key][l].val;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main(){
    TimeMap* timeMap = new TimeMap();
    timeMap->set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    cout << timeMap->get("foo", 1) << " ";         // return "bar"
    cout << timeMap->get("foo", 3) << " ";         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap->set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    cout << timeMap->get("foo", 4) << " ";         // return "bar2"
    cout << timeMap->get("foo", 5) << " ";
    cout << endl;         // return "bar2"

    return 0;
}