#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool diff(string& s1, string& s2){
        int n = s1.length();
        int d = 0;
        for (int i = 0; i < n; i++){
            d += (s1[i] != s2[i]);
            if (d > 2) return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int q = queries.size();
        int n = dictionary.size();
        vector<string> ans;
        for (string& query : queries){
            for (int i = 0; i < n; i++){
                if (diff(query, dictionary[i])){
                    ans.push_back(query);
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<string> queries = {"word","note","ants","wood"};
    vector<string> dictionary = {"wood","joke","moat"};
    // vector<string> queries = {"yes"};
    // vector<string> dictionary = {"not"};
    Solution S;
    vector<string> ans = S.twoEditWords(queries, dictionary);
    for (string s : ans) cout << s << " ";
    cout << endl;
    return 0;
}