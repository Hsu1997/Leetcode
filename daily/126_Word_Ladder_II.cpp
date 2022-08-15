#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int n;
    int ans_length = 0;
    
    int end = -1;
    vector<int> dist;
    vector<vector<int>> parents;
    vector<vector<int>> adj;
    vector<vector<int>> path;
    vector<vector<string>> ans;

    bool adjacent(string a, string b){
        int diff = 0;
        for (int i = 0; i < a.length(); i++){
            if (a[i] != b[i]) diff++;
            if (diff > 1) return false;
        }
        return (diff == 1)? true:false;
    }

    void back_tracking(vector<int>& back_path, int node){
        if (node == 0){
            // back_path.push_back(node);
            path.push_back(back_path);
            // back_path.pop_back();
            return;
        }
        else{
            for (auto i : parents[node]){
                back_path.push_back(i);
                back_tracking(back_path, i);
                back_path.pop_back();
            }
        }
    }

    void trans_path_int_to_string(vector<string> wordList){
        for (auto i : path){
            vector<string> temp;
            for (int j = i.size()-1; j >= 0; j--){
                temp.push_back(wordList[i[j]]);
            }
            ans.push_back(temp);
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.emplace(wordList.begin(), beginWord);
        n = wordList.size();

        adj = vector<vector<int>>(n);
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (adjacent(wordList[i], wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // for (auto i : adj){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        for (int i = 0; i < wordList.size(); i++) if (wordList[i] == endWord) end = i;
        if (end == -1)return {};
        // cout << "end = " << end << endl;

        dist = vector<int>(n, 501);
        dist[0] = 0;
        parents = vector<vector<int>>(n);
        parents[0].push_back(-1);
        queue<int> bfs;
        bfs.push(0);
        bool find = false;

        while(ans_length <= n){
            if (find) break;
            queue<int> temp;
            ans_length++;
            while(!bfs.empty()){
                int now = bfs.front();
                bfs.pop();
                // cout << now << " : ";
                for (auto node : adj[now]){
                    if (node == end) find = true;
                    if (ans_length <= dist[node]){
                        if (ans_length < dist[node]){
                            parents[node].clear();
                            temp.push(node);
                            // cout << node << " ";
                            dist[node] = ans_length;
                        }
                        parents[node].push_back(now);
                    }
                }
                // cout << endl;
            }
            swap(temp, bfs);
        }
        // cout << find << endl;
        if (!find) return {};

        // cout << "dist : ";
        // for (auto i : dist) cout << i << " ";
        // cout << endl;

        // for (auto i : parents){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }

        vector<int> back_path;
        back_path.push_back(end);
        back_tracking(back_path, end);
        trans_path_int_to_string(wordList);

        return ans;
    }
};

int main(){
    // string beginWord = "hit";
    // string endWord = "cog";
    // vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    // string beginWord = "hit";
    // string endWord = "cog";
    // vector<string> wordList = {"hot","dot","dog","lot","log"};
   
    string beginWord = "cet";
    string endWord = "ism";
    vector<string> wordList = {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim"};

    Solution S;
    vector<vector<string>> ans = S.findLadders(beginWord, endWord, wordList);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}