#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct pair_hash{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& a) const{
        int h1 = hash<T1>{}(a.first);
        int h2 = hash<T2>{}(a.second);
        return h1 ^ h2;
    }
};

int main(){
    vector<vector<int>> obstacles = {{1,3},{2,4},{3,4},{1,3}};
    unordered_set<pair<int,int>, pair_hash> s;
    for (auto& obstacle : obstacles){
        s.insert({obstacle[0], obstacle[1]});
    }
    for (auto i : s) cout << i.first << " " << i.second << endl;
    return 0;
}