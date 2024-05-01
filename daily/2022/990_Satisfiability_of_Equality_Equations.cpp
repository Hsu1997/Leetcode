#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> v;

    int find(int i){
        while (v[i] != i) i = v[i];
        return i;
    }

    bool equationsPossible(vector<string>& equations) {
        v = vector<int>(26);
        for (int i = 0; i < 26; i++) v[i] = i;

        for (auto i : equations){
            if (i[1] == '='){
                int a = i[0] - 'a';
                int b = i[3] - 'a';
                v[find(a)] = find(b);
            }
        }

        // for (char i = 'a'; i <= 'j'; i++) cout << i << " ";
        // for (char i = 'k'; i <= 'z'; i++) cout << " " << i << " ";
        // cout << endl;
        // for (auto i : v) cout << i << " ";
        // cout << endl;

        for (auto i : equations){
            if (i[1] == '!'){
                int a = i[0] - 'a';
                int b = i[3] - 'a';
                if (find(a) == find(b)) return false;
            }
        }
        return true;
    }
};

int main(){
    // vector<string> equations = {"a==b","b!=a"};
    // vector<string> equations = {"a==b","b==a"};
    vector<string> equations = {"x==d","i==p","k!=i","m==c","w!=a","c==v","y==l","h==t","m==c","q!=w","l==k","b!=e","h==x","n!=b"};
    // vector<string> equations = {"f==a","a==b","f!=e","a==c","b==e","c==f"};
    Solution S;
    cout << S.equationsPossible(equations) << endl;
    return 0;
}