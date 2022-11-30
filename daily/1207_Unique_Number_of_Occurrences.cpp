#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for (auto i : arr) m[i]++;
        unordered_set<int> s;
        for (auto i : m){
            if (s.count(i.second)) return false;
            s.insert(i.second);
        }
        return true;
    }
};

int main(){
    // vector<int> arr = {1,2,2,1,1,3};
    // vector<int> arr = {1,2};
    vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};

    Solution S;
    cout << S.uniqueOccurrences(arr) << endl;
    return 0;
}