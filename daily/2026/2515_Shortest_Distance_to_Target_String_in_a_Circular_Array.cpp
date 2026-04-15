#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        for (int dis = 0; dis <= n / 2; dis++){
            if (words[(startIndex + dis) % n] == target || words[(startIndex + n - dis) % n] == target) return dis;
        }
        return -1;
    }
};

int main(){
    vector<string> words = {"hello","i","am","leetcode","hello"};
    string target = "hello";
    int startIndex = 1;
    // vector<string> words = {"a","b","leetcode"};
    // string target = "leetcode";
    // int startIndex = 0;
    // vector<string> words = {"i","eat","leetcode"};
    // string target = "ate";
    // int startIndex = 0;
    Solution S;
    cout << S.closestTarget(words, target, startIndex) << endl;
    return 0;
}