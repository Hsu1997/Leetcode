#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers, 0);
        vector<int> online(numberOfUsers, 0);
        auto cmp = [](const vector<string>& a,const vector<string>& b){
            int ta = stoi(a[1]);
            int tb = stoi(b[1]);
            if (ta != tb) return ta < tb;
            if (a[0] == b[0]) return false;
            return a[0] == "OFFLINE";
        };
        sort(events.begin(), events.end(), cmp);
        // for (auto event : events) cout << event[0] << " " << event[1] << " " << event[2] << endl;
        for (vector<string>& event : events){
            if (event[0] == "MESSAGE"){
                if (event[2] == "ALL") for (int i = 0; i < numberOfUsers; i++) ans[i]++;
                else if (event[2] == "HERE"){
                    for (int i = 0; i < numberOfUsers; i++) if (online[i] <= stoi(event[1])) ans[i]++;
                }
                else{
                    string& l = event[2];
                    int idx = 0;
                    while(idx < l.length()){
                        while(idx < l.length() && (l[idx] == 'i' || l[idx] == 'd' || l[idx] == ' ')){
                            idx++;
                        }
                        int curr = 0;
                        while(idx < l.length() && l[idx] != 'i' && l[idx] != 'd' && l[idx] != ' '){
                            curr = curr * 10 + (l[idx] - '0');
                            idx++;
                        }
                        ans[curr]++;
                    }
                }
            }
            else{
                online[stoi(event[2])] = stoi(event[1]) + 60;
            }
        }
        return ans;
    }
};

int main(){
    int numberOfUsers = 2;
    vector<vector<string>> events = {{"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","71","HERE"}};
    // int numberOfUsers = 2;
    // vector<vector<string>> events = {{"MESSAGE","10","id1 id0"},{"OFFLINE","12","0"},{"MESSAGE","12","ALL"}};
    // int numberOfUsers = 2;
    // vector<vector<string>> events = {{"OFFLINE","10","0"},{"MESSAGE","12","HERE"}};
    Solution S;
    vector<int> ans = S.countMentions(numberOfUsers, events);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}