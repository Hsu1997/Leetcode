#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool mutation(string a, string b){
        if (a.length() != 8 || b.length() != 8) return false;
        int diff = 0;
        for (int i = 0; i < 8; i++){
            if (a[i] != b[i]) diff++;
        }
        return diff == 1;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        bool contain_ans = false;
        for (auto i : bank) if (end.compare(i) == 0) contain_ans = true;
        if (!contain_ans) return -1;

        int step = 0;
        vector<string> candidate;
        candidate.push_back(start);
        vector<bool> visited(bank.size(), false);

        while(step <= bank.size()){
            vector<string> temp;
            for (string now : candidate){
                if (now.compare(end) == 0) return step;

                for (int i = 0; i < bank.size(); i++){
                    if (!visited[i] && mutation(now, bank[i])){
                        visited[i] = true;
                        temp.push_back(bank[i]);
                    }
                }
            }
            if (temp.empty()) return -1;
            swap(candidate, temp);
            step++;
        }

        return -1;
    }
};

int main(){
    // string start = "AACCGGTT";
    // string end = "AACCGGTA";
    // vector<string> bank = {"AACCGGTA"};

    // string start = "AACCGGTT";
    // string end = "AAACGGTA";
    // vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};

    string start = "AAAAACCC";
    string end = "AACCCCCC";
    vector<string> bank = {"AAAACCCC","AAACCCCC","AACCCCCC"};
    Solution S;
    cout << S.minMutation(start, end, bank) << endl;
    return 0;
}