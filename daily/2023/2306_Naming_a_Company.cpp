#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        long long ans = 0;
        unordered_set<string> prefix[26];

        for (auto s : ideas){
            prefix[s[0]-'a'].insert(s.substr(1));
        }
        for (int i = 0; i < 25; i++){
            for (int j = i+1; j < 26; j++){
                int temp = 0;
                for (auto s : prefix[i]){
                    if (prefix[j].count(s)) temp++;
                }
                ans += (prefix[i].size() - temp) * (prefix[j].size() - temp);
            }
        }
        return 2 * ans;
    }
};

int main(){
    vector<string> ideas = {"coffee","donuts","time","toffee"};
    // vector<string> ideas = {"lack","back"};
    Solution S;
    cout << S.distinctNames(ideas) << endl;
    return 0;
}