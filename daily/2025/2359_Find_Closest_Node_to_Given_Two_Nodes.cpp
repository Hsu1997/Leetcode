#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> t1(n, -1);
        vector<int> t2(n, -1);
        int n1 = node1;
        int t = 0;
        while(n1 != -1 && t1[n1] == -1){
            t1[n1] = t;
            n1 = edges[n1];
            t++;
        }
        int n2 = node2;
        t = 0;
        while(n2 != -1 && t2[n2] == -1){
            t2[n2] = t;
            n2 = edges[n2];
            t++;
        }
        int ans = -1;
        int dis = INT_MAX;
        for (int i = 0; i < n; i++){
            if (t1[i] == -1 || t2[i] == -1) continue;
            int curr = max(t1[i], t2[i]);
            if (curr < dis){
                dis = curr;
                ans = i;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> edges = {2,2,3,-1};
    int node1 = 0;
    int node2 = 1;
    // vector<int> edges = {1,2,-1};
    // int node1 = 0;
    // int node2 = 2;
    Solution S;
    cout << S.closestMeetingNode(edges, node1, node2) << endl;
    return 0;
}