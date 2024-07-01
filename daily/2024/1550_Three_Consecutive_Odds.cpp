#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int acc = 0;
        for (auto i : arr){
            if (i % 2 == 1) acc++;
            else acc = 0;
            if (acc == 3) return true;
        }
        return false;
    }
};

int main(){
    vector<int> arr = {2,6,4,1};
    // vector<int> arr = {1,2,34,3,4,5,7,23,12};
    Solution S;
    cout << S.threeConsecutiveOdds(arr) << endl;
    return 0;
}