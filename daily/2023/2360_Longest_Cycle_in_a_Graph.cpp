#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int ans = -1;
        vector<int> time(n,-1);
        for (int i = 0; i < n; i++){
            // cout << "now start at " << i << " : ";
            unordered_set<int> s;
            int temp = i;
            int now_time = 0;
            // time[temp] = 0;
            while(edges[temp] != -1 && time[temp] == -1){
                time[temp] = now_time;
                now_time++;
                if (time[edges[temp]] != -1){
                    if (s.count(edges[temp])){
                        // cout << endl << "find circle! The circle has " << now_time - time[edges[temp]] << " edges. ";
                        ans = max(ans, now_time - time[edges[temp]]);
                    }
                    break;
                }
                else{
                    s.insert(temp);
                    temp = edges[temp];
                    // cout << temp << " ";
                }
            }
            // cout << endl << "end of start at " << i << endl;
        }
        return ans;
    }
};

int main(){
    // vector<int> edges = {3,3,4,2,3};
    vector<int> edges = {2,-1,3,1};
    Solution S;
    cout << S.longestCycle(edges) << endl;
    return 0;
}