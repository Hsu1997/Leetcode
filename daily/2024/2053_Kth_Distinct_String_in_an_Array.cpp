#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        for (string s : arr) m[s]++;
        for (string s : arr){
            if (m[s] == 1) k--;
            if (k == 0) return s;
        }
        return "";
    }
};

int main(){
    vector<string> arr = {"d","b","c","b","c","a"};
    int k = 2;
    // vector<string> arr = {"aaa","aa","a"};
    // int k = 1;
    // vector<string> arr = {"a","b","a"};
    // int k = 3;
    Solution S;
    cout << S.kthDistinct(arr, k) << endl;
    return 0;
}