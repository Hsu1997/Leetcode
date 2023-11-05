#include <iostream>
#include <vector>
// #include <queue>

using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int now = arr[0];
        int c = 0;
        for (int i = 1; i < n; i++){
            if (arr[i] > now) now = arr[i], c = 1;
            else c++;
            if (c == k) return now;
        }
        return now;
    }
};

int main(){
    vector<int> arr = {2,1,3,5,4,6,7};
    // vector<int> arr = {1,2,3};
    int k = 2;
    Solution S;
    cout << S.getWinner(arr, k) << endl;
    return 0;
}