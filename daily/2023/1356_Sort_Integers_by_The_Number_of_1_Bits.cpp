#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool compare(int& i, int& j){
        int count_i = __builtin_popcount(i);
        int count_j = __builtin_popcount(j);
        if (count_i == count_j) return i < j;
        else return count_i < count_j;
    };

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};

int main(){
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    // vector<int> arr = {1024,512,256,128,64,32,16,8,4,2,1};
    Solution S;
    vector<int> ans = S.sortByBits(arr);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}