#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (string s : words){
            int acc = 0;
            for (char c : s){
                acc = (acc + weights[c - 'a']) % 26;
            }
            ans += ('a' + 25 - acc);
        }
        return ans;
    }
};

int main(){
    vector<string> words = {"abcd","def","xyz"};
    vector<int> weights = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
    // vector<string> words = {"a","b","c"};
    // vector<int> weights = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    // vector<string> words = {"abcd"};
    // vector<int> weights = {7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5};
    Solution S;
    cout << S.mapWordWeights(words, weights) << endl;
    return 0;
}