#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool mycompare(vector<int> a, vector<int> b){
        return (a[0] != b[0])? a[0] < b[0] : a[1] > b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), mycompare);
        int n = people.size();
        for (int i = n-1; i >= 0; i--){
            vector<int> temp = people[i];
            people.erase(people.begin()+i);
            people.insert(people.begin()+i+temp[1], temp);
        }
        return people;
    }
};

int main(){
    // vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> people = {{1,0}};
    Solution S;
    vector<vector<int>> ans = S.reconstructQueue(people);
    for (auto i : ans){
        cout << "[" << i[0] << "," << i[1] << "]" << " ";
    }
    cout << endl;
    return 0;
}