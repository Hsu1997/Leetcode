#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    struct VectorHasher {
        int operator()(const vector<int> &V) const {
            int hash = 26;
            for(auto &i : V) {
                hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };

    vector<int> convert(string s){
        vector<int> count(26,0);
        for (auto i : s){
            count[i-'a']++;
        }
        return count;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, VectorHasher> m;
        for (string s : strs){
            m[convert(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto i : m){
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution S;
    vector<vector<string>> ans = S.groupAnagrams(strs);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}