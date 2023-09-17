#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int n;
    unordered_map<string, multiset<string>> m;
    vector<string> ans;
    unordered_map<string, int> visited;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        for (auto i : tickets){
            m[i[0]].insert(i[1]);
            visited[i[0]+i[1]]++;
        }
        // for (auto& i : m) sort(i.second.begin(), i.second.end());
        // for (auto i : m){
        //     cout << i.first << " : ";
        //     for (auto j : i.second) cout << j << " ";
        //     cout << endl;
        // }
        dfs("JFK");
        return ans;
    }

    bool dfs(string source){
        ans.push_back(source);
        // for (auto i : ans) cout << i << " ";
        // cout << endl;
        if (ans.size() == n+1) return true;
        for (auto& i : m[source]){
            if (visited[source + i]){
                visited[source + i]--;
                if (dfs(i)) return true;
                visited[source + i]++;
            }
        }
        ans.pop_back();
        return false;
    }
};

int main(){
    // vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    // vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<vector<string>> tickets = {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    Solution S;
    vector<string> ans = S.findItinerary(tickets);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}