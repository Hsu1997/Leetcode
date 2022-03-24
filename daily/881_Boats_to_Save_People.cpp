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
    vector<int> people = {6,5,4,2,6};
    // people.erase(people.begin());
    // for (auto i : people) cout << i << " ";
    // cout << endl;
    int limit = 6;
    Solution S;
    cout << S.numRescueBoats(people, limit) << endl;
    return 0;
}

// class Solution {
// public:
//     int numRescueBoats(vector<int>& people, int limit) {
//         sort(people.begin(), people.end());
//         reverse(people.begin(), people.end());
        
//         // for (auto i : people) cout << i << " ";
//         // cout << endl;
//         vector<int> ans = {};
//         vector<int>::iterator ptr;
//         for (vector<int>::iterator i = people.begin(); i != people.end(); i++){
//             cout << "now is : " << *i << " ";
//             if (ans.empty()){
//                 ans.push_back(*i);
//                 cout << "push " << *i << endl;
//                 continue;
//             }
//             for (ptr = ans.begin(); ptr != ans.end(); ptr++){
//                 if (*ptr + *i > limit) continue;
//                 else{
//                     *ptr += *i;
//                     cout << "plus" << endl;
//                     break;
//                 }
//             }
//             if (ptr == ans.end()){
//                 ans.push_back(*i);
//                 cout << "push " << *i << endl;
//             } 
//         }
//         return ans.size();;
//     }
// };