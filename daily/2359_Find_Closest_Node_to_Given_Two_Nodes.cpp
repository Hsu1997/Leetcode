#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        bool find1 = false;
        bool find2 = false;
        bool circle1 = false;
        bool circle2 = false;
        while(!((node1 == -1 || circle1) && (node2 == -1 || circle2))){
            // cout << "node 1 = " << node1 << ", node 2 = " << node2 << endl;
            if (node1 == node2) return node1;
            if (node2 != -1) find2 = s1.count(node2);
            if (node1 != -1) find1 = s2.count(node1);
            if (find1 && find2) return min(node1,node2);
            if (find1) return node1;
            if (find2) return node2;

            if (node1 != -1){
                if (!circle1 && s1.count(node1)) circle1 = true;
                s1.insert(node1);
            }
            if (node2 != -1){
                if (!circle2 && s2.count(node2)) circle2 = true;
                s2.insert(node2);
                // cout << "s2 insert node2 : " << node2 << ", circle2 = " << circle2 << endl;
            }
            if (node1 != -1) node1 = edges[node1];
            if (node2 != -1) node2 = edges[node2];
        }

        // for (auto i : s1) cout << i << " ";
        // cout << endl;
        // for (auto i : s2) cout << i << " ";
        // cout << endl;

        if (node1 == node2) return node1;
        find2 = s1.count(node2);
        find1 = s2.count(node1);
        if (find1 && find2) return min(node1,node2);
        if (find1) return node1;
        if (find2) return node2;
        return -1;
    }
};

int main(){
    // vector<int> edges = {2,2,3,-1};
    // int node1 = 0;
    // int node2 = 1;
    // vector<int> edges = {1,2,-1};
    // int node1 = 0;
    // int node2 = 2;
    // vector<int> edges = {2,0,0};
    // int node1 = 2;
    // int node2 = 0;
    // vector<int> edges = {4,4,4,5,1,2,2};
    // int node1 = 1;
    // int node2 = 1;
    // vector<int> edges = {5,3,1,0,2,4,5};
    // int node1 = 3;
    // int node2 = 2;
    vector<int> edges = {5,4,5,4,3,6,-1};
    int node1 = 0;
    int node2 = 1;
    Solution S;
    cout << S.closestMeetingNode(edges, node1, node2) << endl;
    return 0;
}