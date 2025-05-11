#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int consecutive = 0;
        for (int i : arr){
            if (i % 2 == 0) consecutive = 0;
            else{
                consecutive++;
                if (consecutive == 3) return true;
            }
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