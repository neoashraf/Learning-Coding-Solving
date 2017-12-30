#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 3;
ll bigmod(ll b, ll p){
    ll ans;
    if(p == 0)
        return 1;
    else if(p & 1==0){
        ans = bigmod(b,p/2);
        ans *= ans;
    }
    else
        ans = (b % mod) * bigmod(b,p-1);
    return ans % mod;
}
///here the return values are moded but
///we do not need to mod the bigmod calls
///in else (we do not need to mod further as for p = 0 it will get 1 then ans will be b%m )
int main(){
    ll  b,p;
    scanf("%lld %lld",&b,&p);
    printf("%lld\n",bigmod(b,p));
    return 0;
}
