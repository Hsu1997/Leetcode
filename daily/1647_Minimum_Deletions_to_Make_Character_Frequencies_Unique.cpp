#include <iostream>
#include <vector>
#include <string>
// #include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int deletions = 0;

        vector<int> count(26,0);
        for (char i : s) count[i-'a']++;

        set<int> S;
        for (auto i : count){
            int now = i;
            while (S.find(now) != S.end() && now > 0) now--;
            if (now != 0) S.insert(now);
            deletions += (i - now);
        }
        
        return deletions;
    }
};

int main(){
    string s = "ceabaacb";
    Solution S;
    cout << S.minDeletions(s) << endl;
    return 0;
}