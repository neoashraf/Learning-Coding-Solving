#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 3;
ll bigmod(ll b, ll p){
    ll i ,ans = 1;
    for(i = 1;i<=p;i++){
        ans *= (b%mod);
        ans %= mod;
    }
    return ans;
}

int main(){
    ll  b,p;
    scanf("%lld %lld",&b,&p);
    printf("%lld\n",bigmod(b,p));
    return 0;
}
