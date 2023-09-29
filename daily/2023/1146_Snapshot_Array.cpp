#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SnapshotArray {
public:
    int snapshot = 0;
    vector<vector<pair<int,int>>> record;

    SnapshotArray(int length) {
        record.resize(length);
        for (int i = 0; i < length; i++) record[i].push_back({0,0});
    }
    
    void set(int index, int val) {
        record[index].push_back({snapshot,val});
    }
    
    int snap() {
        return snapshot++;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int,int>>::iterator it = upper_bound(record[index].begin(), record[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};


// Your SnapshotArray object will be instantiated and called as such:

int main(){
    SnapshotArray* snapshotArr = new SnapshotArray(3); // set the length to be 3
    snapshotArr->set(0,5);  // Set array[0] = 5
    cout << snapshotArr->snap() << endl;  // Take a snapshot, return snap_id = 0
    snapshotArr->set(0,6);
    cout << snapshotArr->get(0,0) << endl;  // Get the value of array[0] with snap_id = 0, return 5
    return 0;
}