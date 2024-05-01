#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node{
    string s;
    bool is_word = false;
    vector<node*> children = vector<node*>(26);
};

class Trie{
public:
    node* root;

    Trie(){
        root = new node();
    }

    void insert(string _s){
        node* temp = root;
        for (auto i : _s){
            if (!temp->children[i-'a']) temp->children[i-'a'] = new node();
            temp = temp->children[i-'a'];
        }
        temp->s = _s;
        temp->is_word = true;
    }
};

class Solution {
public:
    vector<vector<char>> board;
    int n;
    int m;
    Trie T;
    vector<vector<int>> visited;
    string s;
    vector<string> ans;
    vector<int> x = {-1,0,1,0};
    vector<int> y = {0,1,0,-1};

    bool in_range(int a, int b){
        return (a < n && b < m && a >= 0 && b >= 0);
    }
    
    void dfs(int i, int j, vector<vector<int>>& visited, node* now){
        // cout << i << ", " << j << " : " << s << " => ";
        s.push_back(board[i][j]);
        // cout << s << endl;
        visited[i][j] = 1;
        now = now->children[board[i][j]-'a'];
        if (now->is_word){
            now->is_word = false;
            ans.push_back(now->s);
        }

        for (int d = 0; d < 4; d++){
            int nx = i + x[d];
            int ny = j + y[d];
            // cout << in_range(nx, ny) << endl;
            if (in_range(nx, ny) && !visited[nx][ny] && now->children[board[nx][ny] - 'a']) dfs(nx, ny, visited, now);
        }

        visited[i][j] = 0;
        s.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& _board, vector<string>& words) {
        board = _board;
        n = board.size();
        m = board[0].size();
        for (auto i : words) T.insert(i);
        visited = vector<vector<int>>(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                node* temp = T.root;
                if (temp->children[board[i][j]-'a']) dfs(i, j, visited, temp);
            }
        }
        return ans;
    }
};

int main(){
    // vector<vector<char>> board = {{'a','a'}};
    // vector<string> words = {"aaa"};
    // vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    // vector<string> words = {"oath","pea","eat","rain"};
    // vector<vector<char>> board = {{'a','b'},{'c','d'}};
    // vector<string> words = {"abcb"};
    // vector<vector<char>> board = {{'o','a','b','n'},{'o','t','a','e'},{'a','h','k','r'},{'a','f','l','v'}};
    // vector<string> words = {"oa","oaa"};
    // vector<vector<char>> board = {{'a','b'}};
    // vector<string> words = {"ba"};
    // vector<vector<char>> board = {{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'}};
    // vector<string> words = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    vector<vector<char>> board = {{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'},{'b','a','b','a','b','a','b','a','b','a'},{'a','b','a','b','a','b','a','b','a','b'}};
    vector<string> words = {"aababababa","abbabababa","acbabababa","adbabababa","aebabababa","afbabababa","agbabababa","ahbabababa","aibabababa","ajbabababa","akbabababa","albabababa","ambabababa","anbabababa","aobabababa","apbabababa","aqbabababa","arbabababa","asbabababa","atbabababa","aubabababa","avbabababa","awbabababa","axbabababa","aybabababa","azbabababa","bababababa","bbbabababa","bcbabababa","bdbabababa","bebabababa","bfbabababa","bgbabababa","bhbabababa","bibabababa","bjbabababa","bkbabababa","blbabababa","bmbabababa","bnbabababa","bobabababa","bpbabababa","bqbabababa","brbabababa","bsbabababa","btbabababa","bubabababa","bvbabababa","bwbabababa","bxbabababa","bybabababa","bzbabababa","cababababa","cbbabababa","ccbabababa","cdbabababa","cebabababa","cfbabababa","cgbabababa","chbabababa","cibabababa","cjbabababa","ckbabababa","clbabababa","cmbabababa","cnbabababa","cobabababa","cpbabababa","cqbabababa","crbabababa","csbabababa","ctbabababa","cubabababa","cvbabababa","cwbabababa","cxbabababa","cybabababa","czbabababa","dababababa","dbbabababa","dcbabababa","ddbabababa","debabababa","dfbabababa","dgbabababa","dhbabababa","dibabababa","djbabababa","dkbabababa","dlbabababa","dmbabababa","dnbabababa","dobabababa","dpbabababa","dqbabababa","drbabababa","dsbabababa","dtbabababa","dubabababa","dvbabababa","dwbabababa","dxbabababa","dybabababa","dzbabababa","eababababa","ebbabababa","ecbabababa","edbabababa","eebabababa","efbabababa","egbabababa","ehbabababa","eibabababa","ejbabababa","ekbabababa","elbabababa","embabababa","enbabababa","eobabababa","epbabababa","eqbabababa","erbabababa","esbabababa","etbabababa","eubabababa","evbabababa","ewbabababa","exbabababa","eybabababa","ezbabababa","fababababa","fbbabababa","fcbabababa","fdbabababa","febabababa","ffbabababa","fgbabababa","fhbabababa","fibabababa","fjbabababa","fkbabababa","flbabababa","fmbabababa","fnbabababa","fobabababa","fpbabababa","fqbabababa","frbabababa","fsbabababa","ftbabababa","fubabababa","fvbabababa","fwbabababa","fxbabababa","fybabababa","fzbabababa","gababababa","gbbabababa","gcbabababa","gdbabababa","gebabababa","gfbabababa","ggbabababa","ghbabababa","gibabababa","gjbabababa","gkbabababa","glbabababa","gmbabababa","gnbabababa","gobabababa","gpbabababa","gqbabababa","grbabababa","gsbabababa","gtbabababa","gubabababa","gvbabababa","gwbabababa","gxbabababa","gybabababa","gzbabababa","hababababa","hbbabababa","hcbabababa","hdbabababa","hebabababa","hfbabababa","hgbabababa","hhbabababa","hibabababa","hjbabababa","hkbabababa","hlbabababa","hmbabababa","hnbabababa","hobabababa","hpbabababa","hqbabababa","hrbabababa","hsbabababa","htbabababa","hubabababa","hvbabababa","hwbabababa","hxbabababa","hybabababa","hzbabababa","iababababa","ibbabababa","icbabababa","idbabababa","iebabababa","ifbabababa","igbabababa","ihbabababa","iibabababa","ijbabababa","ikbabababa","ilbabababa","imbabababa","inbabababa","iobabababa","ipbabababa","iqbabababa","irbabababa","isbabababa","itbabababa","iubabababa","ivbabababa","iwbabababa","ixbabababa","iybabababa","izbabababa","jababababa","jbbabababa","jcbabababa","jdbabababa","jebabababa","jfbabababa","jgbabababa","jhbabababa","jibabababa","jjbabababa","jkbabababa","jlbabababa","jmbabababa","jnbabababa","jobabababa","jpbabababa","jqbabababa","jrbabababa","jsbabababa","jtbabababa","jubabababa","jvbabababa","jwbabababa","jxbabababa","jybabababa","jzbabababa","kababababa","kbbabababa","kcbabababa","kdbabababa","kebabababa","kfbabababa","kgbabababa","khbabababa","kibabababa","kjbabababa","kkbabababa","klbabababa","kmbabababa","knbabababa","kobabababa","kpbabababa","kqbabababa","krbabababa","ksbabababa","ktbabababa","kubabababa","kvbabababa","kwbabababa","kxbabababa","kybabababa","kzbabababa","lababababa","lbbabababa","lcbabababa","ldbabababa","lebabababa","lfbabababa","lgbabababa","lhbabababa","libabababa","ljbabababa","lkbabababa","llbabababa","lmbabababa","lnbabababa","lobabababa","lpbabababa","lqbabababa","lrbabababa","lsbabababa","ltbabababa","lubabababa","lvbabababa","lwbabababa","lxbabababa","lybabababa","lzbabababa","mababababa","mbbabababa","mcbabababa","mdbabababa","mebabababa","mfbabababa","mgbabababa","mhbabababa","mibabababa","mjbabababa","mkbabababa","mlbabababa","mmbabababa","mnbabababa","mobabababa","mpbabababa","mqbabababa","mrbabababa","msbabababa","mtbabababa","mubabababa","mvbabababa","mwbabababa","mxbabababa","mybabababa","mzbabababa","nababababa","nbbabababa","ncbabababa","ndbabababa","nebabababa","nfbabababa","ngbabababa","nhbabababa","nibabababa","njbabababa","nkbabababa","nlbabababa","nmbabababa","nnbabababa","nobabababa","npbabababa","nqbabababa","nrbabababa","nsbabababa","ntbabababa","nubabababa","nvbabababa","nwbabababa","nxbabababa","nybabababa","nzbabababa","oababababa","obbabababa","ocbabababa","odbabababa","oebabababa","ofbabababa","ogbabababa","ohbabababa","oibabababa","ojbabababa","okbabababa","olbabababa","ombabababa","onbabababa","oobabababa","opbabababa","oqbabababa","orbabababa","osbabababa","otbabababa","oubabababa","ovbabababa","owbabababa","oxbabababa","oybabababa","ozbabababa","pababababa","pbbabababa","pcbabababa","pdbabababa","pebabababa","pfbabababa","pgbabababa","phbabababa","pibabababa","pjbabababa","pkbabababa","plbabababa","pmbabababa","pnbabababa","pobabababa","ppbabababa","pqbabababa","prbabababa","psbabababa","ptbabababa","pubabababa","pvbabababa","pwbabababa","pxbabababa","pybabababa","pzbabababa","qababababa","qbbabababa","qcbabababa","qdbabababa","qebabababa","qfbabababa","qgbabababa","qhbabababa","qibabababa","qjbabababa","qkbabababa","qlbabababa","qmbabababa","qnbabababa","qobabababa","qpbabababa","qqbabababa","qrbabababa","qsbabababa","qtbabababa","qubabababa","qvbabababa","qwbabababa","qxbabababa","qybabababa","qzbabababa","rababababa","rbbabababa","rcbabababa","rdbabababa","rebabababa","rfbabababa","rgbabababa","rhbabababa","ribabababa","rjbabababa","rkbabababa","rlbabababa","rmbabababa","rnbabababa","robabababa","rpbabababa","rqbabababa","rrbabababa","rsbabababa","rtbabababa","rubabababa","rvbabababa","rwbabababa","rxbabababa","rybabababa","rzbabababa","sababababa","sbbabababa","scbabababa","sdbabababa","sebabababa","sfbabababa","sgbabababa","shbabababa","sibabababa","sjbabababa","skbabababa","slbabababa","smbabababa","snbabababa","sobabababa","spbabababa","sqbabababa","srbabababa","ssbabababa","stbabababa","subabababa","svbabababa","swbabababa","sxbabababa","sybabababa","szbabababa","tababababa","tbbabababa","tcbabababa","tdbabababa","tebabababa","tfbabababa","tgbabababa","thbabababa","tibabababa","tjbabababa","tkbabababa","tlbabababa","tmbabababa","tnbabababa","tobabababa","tpbabababa","tqbabababa","trbabababa","tsbabababa","ttbabababa","tubabababa","tvbabababa","twbabababa","txbabababa","tybabababa","tzbabababa","uababababa","ubbabababa","ucbabababa","udbabababa","uebabababa","ufbabababa","ugbabababa","uhbabababa","uibabababa","ujbabababa","ukbabababa","ulbabababa","umbabababa","unbabababa","uobabababa","upbabababa","uqbabababa","urbabababa","usbabababa","utbabababa","uubabababa","uvbabababa","uwbabababa","uxbabababa","uybabababa","uzbabababa","vababababa","vbbabababa","vcbabababa","vdbabababa","vebabababa","vfbabababa","vgbabababa","vhbabababa","vibabababa","vjbabababa","vkbabababa","vlbabababa","vmbabababa","vnbabababa","vobabababa","vpbabababa","vqbabababa","vrbabababa","vsbabababa","vtbabababa","vubabababa","vvbabababa","vwbabababa","vxbabababa","vybabababa","vzbabababa","wababababa","wbbabababa","wcbabababa","wdbabababa","webabababa","wfbabababa","wgbabababa","whbabababa","wibabababa","wjbabababa","wkbabababa","wlbabababa","wmbabababa","wnbabababa","wobabababa","wpbabababa","wqbabababa","wrbabababa","wsbabababa","wtbabababa","wubabababa","wvbabababa","wwbabababa","wxbabababa","wybabababa","wzbabababa","xababababa","xbbabababa","xcbabababa","xdbabababa","xebabababa","xfbabababa","xgbabababa","xhbabababa","xibabababa","xjbabababa","xkbabababa","xlbabababa","xmbabababa","xnbabababa","xobabababa","xpbabababa","xqbabababa","xrbabababa","xsbabababa","xtbabababa","xubabababa","xvbabababa","xwbabababa","xxbabababa","xybabababa","xzbabababa","yababababa","ybbabababa","ycbabababa","ydbabababa","yebabababa","yfbabababa","ygbabababa","yhbabababa","yibabababa","yjbabababa","ykbabababa","ylbabababa","ymbabababa","ynbabababa","yobabababa","ypbabababa","yqbabababa","yrbabababa","ysbabababa","ytbabababa","yubabababa","yvbabababa","ywbabababa","yxbabababa","yybabababa","yzbabababa","zababababa","zbbabababa","zcbabababa","zdbabababa","zebabababa","zfbabababa","zgbabababa","zhbabababa","zibabababa","zjbabababa","zkbabababa","zlbabababa","zmbabababa","znbabababa","zobabababa","zpbabababa","zqbabababa","zrbabababa","zsbabababa","ztbabababa","zubabababa","zvbabababa","zwbabababa","zxbabababa","zybabababa","zzbabababa"};
    Solution S;
    vector<string> ans = S.findWords(board, words);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}