#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        target.insert(target.begin(), 0);
        vector<string> ans;
        for (int i = 1; i < target.size(); i++){
            for (int k = 0; k < target[i] - target[i-1] - 1; k++){
                ans.push_back({"Push"});
                ans.push_back({"Pop"});
            }
            ans.push_back("Push");
        }
        return ans;
    }
};

int main(){
    // vector<int> target = {1,3};
    // int n = 3;
    // vector<int> target = {1,2,3};
    // int n = 3;
    vector<int> target = {1,2};
    int n = 4;
    Solution S;
    vector<string> ans = S.buildArray(target, n);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}