#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <unordered_set>

using namespace std;

class Group {
public:
    vector<int> group;

    Group(int n){
        group = vector<int>(n);
        iota(group.begin(), group.end(), 0);
    }

    int find(int i){
        return (group[i] == i)? i : group[i] = find(group[i]);
    }

    void combine(int i, int j){
        group[find(i)] = find(j);
    }
};

class Solution {
public:
    int n;

    bool compare_two_string(string& a, string& b){
        int l = a.length();
        int phrase = 0;
        int temp = -1;
        for (int i = 0; i < l; i++){
            if (a[i] == b[i]) continue;
            if (phrase == 0){
                temp = i;
                phrase = 1;
            }
            else if (phrase == 1){
                if (a[temp] != b[i] || a[i] != b[temp]) return false;
                phrase = 2;
            }
            else{
                return false;
            }
        }
        if (phrase == 1) return false;
        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        Group g(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (compare_two_string(strs[i], strs[j])) g.combine(i, j);
            }
        }

        // for (auto i : g.group) cout << i << " ";
        // cout << endl;

        unordered_set<int> s;
        for (int i = 0; i < n; i++){
            s.insert(g.find(g.group[i]));
        }

        return s.size();
    }
};

int main(){
    // vector<string> strs = {"tars","rats","arts","star"};
    // vector<string> strs = {"omv","ovm"};
    vector<string> strs = {"kccomwcgcs","socgcmcwkc","sgckwcmcoc","coswcmcgkc","cowkccmsgc","cosgmccwkc","sgmkwcccoc","coswmccgkc","kowcccmsgc","kgcomwcccs"};
    Solution S;
    cout << S.numSimilarGroups(strs) << endl;
    return 0;
}