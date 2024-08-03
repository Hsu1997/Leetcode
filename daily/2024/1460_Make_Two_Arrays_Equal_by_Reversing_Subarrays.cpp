#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> m;
        for (int i : target) m[i]++;
        for (int i : arr) m[i]--;
        for (auto i : m) if (i.second != 0) return false;
        return true;
    }
};

int main(){
    vector<int> target = {1,2,3,4};
    vector<int> arr = {2,4,1,3};
    // vector<int> target = {7};
    // vector<int> arr = {7};
    // vector<int> target = {3,7,9};
    // vector<int> arr = {3,7,11};
    Solution S;
    cout << S.canBeEqual(target, arr) << endl;
    return 0;
}