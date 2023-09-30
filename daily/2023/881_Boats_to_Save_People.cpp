#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size() - 1;
        while(i <= j){
            ans++;
            if (people[i] + people[j] <= limit){
                i++;
            }
            j--;
        }
        return ans;
    }
};

int main(){
    vector<int> people = {1,2};
    int limit = 3;
    // vector<int> people = {6,5,4,2,6};
    // int limit = 6;
    Solution S;
    cout << S.numRescueBoats(people, limit) << endl;
    return 0;
}