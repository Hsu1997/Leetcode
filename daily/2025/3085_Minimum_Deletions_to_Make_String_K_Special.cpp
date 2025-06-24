#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int count[26] = {};
        for (char c : word) count[c - 'a']++;
        vector<int> c;
        for (int i : count) if (i > 0) c.push_back(i);
        sort(c.begin(), c.end());
        int ans = INT_MAX;
        int n = c.size();
        int acc = 0;
        for (int i = 0; i < n; i++){
            int curr = acc;
            for (int j = i + 1; j < n; j++){
                curr += max(0, c[j] - c[i] - k);
            }
            ans = min(ans, curr);
            acc += c[i];
        }
        return ans;
    }
};

int main(){
    string word = "aabcaba";
    int k = 0;
    // string word = "dabdcbdcdcd";
    // int k = 2;
    // string word = "aaabaaa";
    // int k = 2;
    Solution S;
    cout << S.minimumDeletions(word, k) << endl;
    return 0;
}