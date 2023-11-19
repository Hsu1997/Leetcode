#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(), flowers.end());
        priority_queue<int,vector<int>, greater<int>> wither;
        int i = 0;
        int flower = 0;
        vector<int> ans;
        vector<int> sorted_people = people;
        sort(sorted_people.begin(), sorted_people.end());
        unordered_map<int,int> people_flower;
        for (int p = 0; p < sorted_people.size(); p++){
            int arrive_time = sorted_people[p];
            while(i < flowers.size() && flowers[i][0] <= arrive_time) flower++, wither.push(flowers[i][1]), i++;
            while(!wither.empty() && wither.top() < arrive_time) flower--, wither.pop();
            people_flower[arrive_time] = flower;
        }
        for (int i = 0; i < people.size(); i++) ans.push_back(people_flower[people[i]]);
        return ans;
    }
};

int main(){
    // vector<vector<int>> flowers = {{1,6},{3,7},{9,12},{4,13}};
    // vector<int> people = {2,3,7,11};
    vector<vector<int>> flowers = {{1,10},{3,3}};
    vector<int> people = {3,3,2};
    Solution S;
    vector<int> ans = S.fullBloomFlowers(flowers, people);
    for (auto i : ans) cout << i << " ";
    cout << endl;
}