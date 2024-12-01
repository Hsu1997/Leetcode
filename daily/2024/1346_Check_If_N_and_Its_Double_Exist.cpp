#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int i : arr){
            if (s.find(i*2) != s.end() || (i % 2 == 0 && s.find(i/2) != s.end())) return true;
            s.insert(i);
        }
        return false;
    }
};

int main(){
    vector<int> arr = {10,2,5,3};
    // vector<int> arr = {3,1,7,11};
    Solution S;
    cout << S.checkIfExist(arr) << endl;
    return 0;
}