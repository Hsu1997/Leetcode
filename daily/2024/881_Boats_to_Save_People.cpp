#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i = 0;
        int j = people.size() - 1;
        sort(people.begin(), people.end());
        int ans = 0;
        while(i <= j){
            if (people[i] + people[j] <= limit) i++, j--;
            else j--;
            ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> people = {1,2};
    int limit = 3;
    // vector<int> people = {3,2,2,1};
    // int limit = 3;
    // vector<int> people = {3,5,3,4};
    // int limit = 5;
    Solution S;
    cout << S.numRescueBoats(people, limit) << endl;
    return 0;
}