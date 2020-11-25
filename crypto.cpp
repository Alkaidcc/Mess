#include <iostream>
#include <string>
using namespace std;
typedef long long LL;

string str = "B!ofx!jowfstf!ifbu!dpoevdujpo!gsbnfxpsl!gps!4E!jnbhjoh!sfdpotusvdujpo!jt!qspqptfe!jo!uijt!qbqfs/!Gjstu-!uif!cbtjd!jefb!up!vtf!uif!JID!gps!4E!ebnbhf!jnbhjoh!jt!ejtdvttfe!boe!gpsnvmbufe/Uif!qspqptfe!JID!jodmveft!uisff!nbkps!dpnqpofout;!gpsxbse!uifsnbm!bobmztjt!tpmwfs-!bekpjou!nfuipe!gps!fggjdjfou!tfotjujwjuz!bobmztjt-!boe!dpokvhbuf!hsbejfou!nfuipe!xjui!dpotusbjout!gps!pqujnbm!jowfstf!tpmvujpot/!Gpmmpxjoh!uijt-!uif!qspqptfe!JID!gsbnfxpsl!jt!bqqmjfe!up!b!tjnqmf!pof!ejnfotjpobm!qspcmfn!up!jmmvtusbuf!uif!lfz!tufqt/!Ofyu-!uxp!bqqmjdbujpo!fybnqmft!jo!4E!bsf!jowftujhbufe/!Tqfdjbm!gpdvtft!po!uif!efufdubcjmjuz-!dpowfshfodf-!boe!spcvtuoftt!bsf!ejtdvttfe!jo!efubjm/!Gjobmmz-!tfwfsbm!dpodmvtjpot!boe!gvuvsf!xpsl!bsf!esbxo!cbtfe!po!uif!qspqptfe!tuvez!boe!ovnfsjdbm!sftvmut/";
void solve(string& s);

class crypto
{
private:
    LL n;
    LL e;
    LL d;
    LL arr[10001] = {0};
public:
    crypto(LL a, LL b, LL c):n(a),e(b),d(c){}
    LL Fast_power(LL a, LL b, LL p);
    void Encode(string str);
    void Decode();
};
LL crypto::Fast_power(LL a,LL b, LL p){
    LL c = 1;
    while (b)
    {
        if (b & 1)
            c = c * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return c;
}

void crypto::Encode(string str){
    int length = str.size();
    for(int i = 0;i < length;i++){
        arr[i] = Fast_power(str[i], e, n);
        cout << arr[i] << " ";
    }
    cout << endl;
}
void crypto::Decode(){
    for(int i = 0;arr[i] != 0;i++){
        putchar(Fast_power(arr[i], d, n));
    }
    cout << endl;
}

int main(){
    cout << "原始密文：" << endl;
    cout << str << endl;
    cout << "明文: " << endl;
    solve(str);
    cout << endl;
    crypto c(472987,134743,7);
    cout << "密文: " << endl;
    c.Encode(str);
    cout << "明文: " << endl;
    c.Decode();
    system("pause");
    return 0;
}
void solve(string& s){
    for(int i = 0;i < s.length();i++){
        s[i]--;
    }
    cout << s;
}
