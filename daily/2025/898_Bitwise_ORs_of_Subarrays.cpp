#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> prev;
        for (int end = 0; end < arr.size(); end++){
            unordered_set<int> temp;
            for (auto i : prev) temp.insert(i | arr[end]);
            temp.insert(arr[end]);
            for (auto i : temp) ans.insert(i);
            prev = temp;
        }
        return ans.size();
    }
};

int main(){
    vector<int> arr = {0};
    // vector<int> arr = {1,1,2};
    // vector<int> arr = {1,2,4};
    Solution S;
    cout << S.subarrayBitwiseORs(arr) << endl;
    return 0;
}