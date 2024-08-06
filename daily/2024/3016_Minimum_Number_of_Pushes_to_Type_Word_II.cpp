#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26,0);
        for (char c : word) count[c-'a']++;
        
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i : count) if (i != 0) pq.push(i);
        int ans = 0;
        int diff_char = 0;
        while(!pq.empty()){
            int c = pq.top();
            pq.pop();
            ans += c * (diff_char / 8 + 1);
            diff_char++;
        }
        return ans;
    }
};

int main(){
    // string word = "abcde";
    // string word = "xyzxyzxyzxyz";
    string word = "aabbccddeeffgghhiiiiii";
    Solution S;
    cout << S.minimumPushes(word) << endl;
    return 0;
}