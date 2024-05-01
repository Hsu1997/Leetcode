#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int position(char i){
        if (i >= 'a' && i <= 'z') return i - 'a';
        else if (i >= 'A' && i <= 'Z') return i - 'A' + 26;
        else return i - '0' + 52;
    }
    
    string frequencySort(string s) {
        vector<pair<int, char>> count(62);
        for (int i = 0; i < 26; i++){
            count[i].second = 'a'+i;
            count[i+26].second = 'A'+i;
        }
        for (int i = 0; i < 10; i++){
            count[i+52].second = '0'+i;
        }

        for (auto i : s) count[position(i)].first++;
        sort(count.begin(), count.end());
        string ans;
        for (int i = 61; i >= 0; i--){
            if (count[i].first == 0) break;
            ans += string(count[i].first, count[i].second);
        }
        return ans;
    }
};

int main(){
    // string s = "tree";
    // string s = "cccaaa";
    // string s = "Aabb";
    string s = "2a554442f544asfasssffffasss";
    Solution S;
    cout << S.frequencySort(s) << endl;
    return 0;
}