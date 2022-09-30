#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        string s;
        int i = 0;
        int j = -1;
        char prev = '.';
        while(i < dominoes.length()){
            while (i < dominoes.length() && dominoes[i] == '.') i++;
            if (i == dominoes.length()) break;
            j = i + 1;
            while (j < dominoes.length() && dominoes[j] == '.') j++;
            if (j == dominoes.length()) break;
            
            // cout << i << " " << j << ":"; 
            if (dominoes[i] == 'R' && dominoes[j] == 'L'){
                while(s.length() < i) s += (prev == 'R')? 'R' : '.';
                for(int k = 0; k < (j-i+1)/2; k++) s += 'R';
                if ((j-i+1)%2 == 1) s += '.';
                for(int k = 0; k < (j-i+1)/2; k++) s += 'L';
                prev = dominoes[j];
                i = j + 1;
                j = -1;
            }
            else{
                if (dominoes[i] == 'L') while(s.length() < i) s += 'L';
                else{
                    if (prev == 'L') while(s.length() < i) s += '.';
                    else while(s.length() < i) s += prev;
                }
                while(s.length() < i) s += (dominoes[i] == 'L')? 'L' : '.';
                s += dominoes[i];
                prev = dominoes[i];
                i = j;
                j = -1;
            }
            // cout << s << endl;
        }

        // cout << "break" << endl;

        if (i < dominoes.length() && dominoes[i] == 'L') while(s.length() <= i) s += 'L';
        if (i < dominoes.length() && dominoes[i] == 'R'){
            while(s.length() < i) s += (prev == 'L')? '.':prev;
            while(s.length() < dominoes.length()) s += 'R';
        }

        while(s.length() < dominoes.length()) s += '.';
        return s;
    }
};

int main(){
    // string dominoes = "RR.L";
    // string dominoes = ".L.R...LR..L..";
    // string dominoes = ".L.R.";
    // string dominoes = "RR.L";
    // string dominoes = "R..L..R..LR.R.R.....";
    string dominoes = ".RR..";
    Solution S;
    cout << S.pushDominoes(dominoes) << endl;
    return 0;
}