#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static bool mycompare(pair<int, string> a, pair<int, string> b){
        if (a.first != b.first) return a > b;
        else{
            return a.second < b.second;
        }
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> c;
        vector<pair<int, string>> node;
        for (auto i : words) c[i]++;
        for (auto i : c) node.push_back(make_pair(i.second, i.first));
        sort(node.begin(), node.end(), mycompare);
        vector<string> ans;
        for (int i = 0; i < k; i++) ans.push_back(node[i].second); 
        return ans;
    }
};

int main(){
    // vector<string> words = {"i","love","leetcode","i","love","coding"};
    // int k = 2;
    vector<string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    int k = 4;
    Solution S;
    vector<string> ans = S.topKFrequent(words, k);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}