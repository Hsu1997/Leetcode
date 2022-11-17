#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ans = 0;

    bool unique(string s){
        bitset<32> b = 0;
        for (auto i : s){
            if (b[i-'a'] > 0)  return false;
            b[i-'a'] = 1;
            // cout << b << endl;
        }
        return true;
    }

    void check(vector<string>& arr, string s, int i){
        if (!unique(s)) return;
        if (s.length() > ans){
            ans = s.length();
            // cout << s << endl;
        }
        for (int k = i; k < arr.size(); k++){
            check(arr, s + arr[k], k+1);
        }
    }

    int maxLength(vector<string>& arr) {
        check(arr, "", 0);
        return ans;
    }
};

int main(){
    // vector<string> arr = {"un","iq","ue"};
    // vector<string> arr = {"cha","r","act","ers"};
    // vector<string> arr = {"abcdefghijklmnopqrstuvwxyz"};
    vector<string> arr = {"ab","cd","cde","cdef","efg","fgh","abxyz"};
    Solution S;
    cout << S.maxLength(arr) << endl;
    return 0;
}