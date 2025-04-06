#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int Max = 1e9 + 1;
        int n = nums.size();
        vector<int> prev(n, -1);
        for (int i = 1; i < n; i++) prev[i] = i-1;
        vector<int> next(n, -1);
        for (int i = 0; i + 1 < n; i++) next[i] = i+1;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) v[i] = nums[i];
        int ops = 0;
        int bad = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        for (int i = 0; i+1 < n; i++){
            if (v[i] > v[i+1]) bad++;
            pq.push({v[i] + v[i+1], i});
        }
        while(bad){
            auto [sum, f] = pq.top();
            pq.pop();
            int s = next[f];
            if (s == -1 || v[f] + v[s] != sum) continue;
            next[f] = next[s];
            if (next[s] != -1) prev[next[s]] = f;
            if (v[f] > v[s]) bad--;
            int left = prev[f];
            int right = next[s];
            if (left != -1){
                pq.push({v[left] + sum, left});
                if (v[left] > v[f]) bad--;
                if (v[left] > sum) bad++;
            }
            if (right != -1){
                pq.push({sum + v[right], f});
                if (v[s] > v[right]) bad--;
                if (sum > v[right]) bad++;
            }
            v[f] += v[s];
            v[s] = Max;
            ops++;
        }
        return ops;
    }
};

int main(){
    // vector<int> nums = {5,2,3,1};
    // vector<int> nums = {1,2,2};
    // vector<int> nums = {3,4,1,1,-3,2,4,3};
    vector<int> nums = {-85529083,50623755,137256618,-61570376,-126713871,28826144,-16719957,-105112342,129065525,103867114,-26922265,-131506900,-95911412,-47467004,-14997164,-127582145,-134804061,33310540,142798940,-13145840,65166170,35068653,18595615,-132201277,25180671,144004972,-129552715,-3344878,73634657,-79910753,-19236130,99402308,7743344,-86821450,119281472,-6068119,81243915,-102846134,-96211242,-40700764,61343170,55808619,-117988802,38226108,-143241943,-131844717,-3176334,1949193,138201727,87533333,-29245467,-47737669,-129572839,-113624184,63102760,109509982,26289482,-36690573,5179672,20046003,-1931819,-92066426,115806233,-43978252,-35018552,98729017,-7624702,-144395150,-63853205,51050102,-55212280,-95646785,41889766,-117036314,-115107912,67156211,-42583779,75176751,-65622385,-21674094,91983598,91832589,66890439,-71815689,133219798,52920160,42945411,-116325290,115565827,118588545,23909767,39558897,-114532846,91304111,-101519640,4674156,28826194,-43443706,81718209,-3400726,6714297,80951282,-132070257,140901812,-20333337,-108918823,46606967,110512652,-21634460,-82025702,41372932,-84218845,-62741015,-52234402,124578366,-28252652,110078650,113550788,101825470,15946063,135042613,-78037718,48655417,-35739568,4696071,117224658,132781377,42641053,-38961442,92279700,-118793824,63525502,47634544,8477718,30391775,-135937793,104765233,93453925,-130922374,-127323012,10761157,92824837,111566892,26794662,77030700,-31102364,83066241,131109967,2422623,76185512,55907931,-87390549,-123240792,67173778,-137794748,-106524498,136373171,20243314,-114768495,133751614,18386218,127578482,21372637,139926658,116153651,31269839,21299894,-132904148,-19440315,76704010,-76752615,-17595611,98587335,-16884259,-55298770,85161966,-22817391,41923630,124915890,14371783,-23640168,33695877,44641461,-140445978,-141898117,24648653,-7653128,50727563,67658018,-116321273,60538195,113761456,-140599962,69464759,-53912949,126830164,98375650,55663908,-5679411,-10129308,82657297,-69939062,-94534507,-4260696,-36174843,-17832515,-65519716,100564624,1048242,124749241,-115719961,-116358476,130154990,-125982265,-77854899,-25477289,-97827290,33557892,-82813819,-41593654,-10239959,-79434173,7316102,103929866,-61290435,11154820,91371707,135673773,140036949,14582157,143510312,138028854,-23583427,-43807034,-72791445,138004727,86227582,131626127,-10865565,121424049,59818709,74911091,80930170,72812698,124045476,30058336,121742111,-26481433,98459112,-140869759,99226833,-3983006,142468270,-72201794,82515172,-9007858,114541461,61560614,69105969,-54497878,-85467796,82352124,-101292276,-112457210,-57176128,100155771,-47692029,-116908283,118435370,-66553332,63565770,-125630247,-60907449,-101920317,95570162,-105922593,-55827535,75003912,-13080123,-137564947,106545963,24344594,-40245335,-140624134,25339703,54210225,31993064,-16833211,-41040130,108957699,-46518716,118442108,67228301,48967180,-7178076,-79513587,-98427583,-23878398,-34584836,9185719,43032055,-129932354,9216391,137764679,-92388083,-102238613,-21612280,-83270757,124347185,-2445023,-127793591,-29578162,58781834,141627088,-47014874,-135502385,133019674,101361757,-50454714,-62681594,-2467899,105192876,-128051374,-49488675,50533648,-119151660,39911795,51203007,20751313,-70085710,-18828646,-1396218,-61301330,35482151,93909846,-18465883,-63615559,81448059,-130193528,-123478870,114279135,-13566817,84127155,72921321,-23389659,-99965725,-70375668,-95044592,-107181250,27224491,61829314,76739737,-128076697,-47097016,114181948,41365044,66519042,-63985171,-57463865,-49644826,-138515113,42222033,-70115557,24628632,127553392,94836363,-60966228,59249536,-2124856,5594572,-12916940,-42138366,-34827090,43394770,60979021,23742668,-60353108,78883238,6241787,-111467752,51731393,-63040860,6217067,52954921,-7819205,8572100,49455425,35437977,81630380,-27431672,59817959,-13108694,70622951,126333035,-90232943,-108578736,-57594042,125542865,-112775787,141527706,-30037993,-94327987,110277765,72676691,-19174747,-30382172,19028510,-52321987,21629697,-51097636,-805599,-87068163,-86376665,41690026,-31951145,127867379,61865793,-2716880,-49980279,-122186093,-31161407,-22618368,59981822,73095419,55071415,-61438139,-75935827,-63575648,109597957,17914138,141272971,-87031623,-70485163,-46903680,-138440851,109633453,137723066,56532202,-47286550,-89693887,80612748,-126853749,36071215,-70710991,-141901128,115186553,-14369229,74545464,22673668,9259356,97699138,-110079586,50008834,20079708,-72471153,-115683931,45606427,-119371855,-64043976,44483247,-46227234,-26538626,-96346760,-65141857,-130724366,28717790,5594391,131786724,78458613,130291470,-73417424,81064167,106005527,56035468,-16706644,34464747,114414092,-67042626,118896321,2943124,48902379,108509179,-33195225,102343293,76601929,-84635224,21003440,-89716602,50714689,-110304031,-7649750,-63866622,93013483,43834718,-66034973,-22676298,-25818352,121894736,-131288475,99055409,-54699411,-12135309,50722610,60526155,9308263,105945851,52537230,61079080,-94636620,-116710945,10541878,50102985,-69099803,-90773579,27573436,58115337,-134316135,85186940,-116710784,-139329182,-124567813,-61307924,-92044903,-64116753,15321297,-92144643,-103436343,-137765325,16992107,97652087,-71356363,-130248542,75082592,68220754,-141952723,-93374598,-23070191,-123507397,109268341,-8065863,-80966660,-10384014,-91098389,48214731,49430997,-6361543,-56658491,61321169,7958907,129045927,-139225578,-45236897,128062554,-69621749,-18793347,-38666912,101065682,89333753,-73718360,-201570,-12582244,1284171,27413183,-5572238,-116785390,14328658,98257765,47692891,29267438,-139677826,19662854,107414503,39112279,-135172922,-117697971,20628642,-78469738,-52788009,37258808,-75134715,-137679943,-106608254,81649063,74882950,-137845694,-60586373,-140245302,113476666,39598806,-24171678,-128535790,-140530935,111432889,-48359050,12718682,-47413510,129837567,-58414515,-95662927};
    Solution S;
    cout << S.minimumPairRemoval(nums) << endl;
    return 0;
}