#include <iostream>
#include <string.h>
typedef long long LL;
const LL n = 472987, e = 134743, d = 7;
using namespace std;

LL crypto[1000];
//¿ìËÙÃÝ
LL Fast_power(LL a, LL b, LL p)
{
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

int main()
{   char s[] ="A new inverse heat conduction framework for 3D imaging reconstruction is proposed in this paper. First, the basic idea to use the IHC for 3D damage imaging is discussed and formulated.The proposed IHC includes three major components: forward thermal analysis solver, adjoint method for efficient sensitivity analysis, and conjugate gradient method with constraints for optimal inverse solutions. Following this, the proposed IHC framework is applied to a simple one dimensional problem to illustrate the key steps. Next, two application examples in 3D are investigated. Special focuses on the detectability, convergence, and robustness are discussed in detail. Finally, several conclusions and future work are drawn based on the proposed study and numerical results.";
    int length = strlen(s);
    for(int i = 0;i < length;i++){
        crypto[i] = Fast_power(s[i],e,n);
        cout << crypto[i] << " ";
    }
    cout << endl;
    for(int i = 0;crypto[i] != 0;i++){
        int b = Fast_power(crypto[i],d,n);
        putchar(b);
    }
    system("pause");
    return 0;
}
