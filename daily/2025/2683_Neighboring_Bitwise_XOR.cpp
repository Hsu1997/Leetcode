#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int num = 0;
        for (int i = 0; i < n; i++){
            num ^= derived[i];
        }
        return num == 0;
    }
};

int main(){
    vector<int> derived = {1,1,0};
    // vector<int> derived = {1,1};
    // vector<int> derived = {1,0};
    Solution S;
    cout << S.doesValidArrayExist(derived) << endl;
    return 0;
}