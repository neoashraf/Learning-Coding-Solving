
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;

#define     mem(x,y)   memset(x,y,sizeof(x))
#define     PB(x)      push_back(x)
#define     POB()      pop_back()
#define     SZ(a)      a.size()
#define     len(a)     strlen(a)
#define     SQR(a)     (a*a)
#define     dig(a)     a-'0'
#define     all(v)     v.begin(),v.end()
#define     read(a)    scanf("%lld",&a)
#define     read2(a,b) scanf("%d %d",&a,&b)
#define     read3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define     cread(a)    scanf("%I64d",&a)
#define     cread2(a,b) scanf("%I64d %I64d",&a,&b)
#define     cread3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define     write(a)   printf("%d",a);
#define     nl         printf("\n")
#define     fr(i,a,b)  for(i=a;i<=b;i++)
#define     rfr(i,a,b) for(i=a;i>=b;i--)
#define     nfr(i,a,b)  for(i=a;i<b;i++)
#define     nrfr(i,a,b) for(i=a;i>b;i--)
#define     sf  scanf
#define     pf  printf
#define     mkp make_pair
#define     fs  first
#define     sd  second

#define     inf  1<<25
#define     sz   1000006
#define     primeLimit  1000005
#define     eps  1e-9
#define     mod  1000000007
#define     PI   2.0*acos(0.0)
#define     imax 2147483647
#define     lmax 9223372036854775807LL

ll pow2[100];

ll bsearch(ll x){
    ll l = 0,u = 62,m;
    while(l<=u){
        m = (l + u)/2;
        if(pow2[m] == x)
            return pow2[m];
        else if(x > pow2[m])
            l = m + 1;
        else
            u = m - 1;
    }
    return pow2[u];
}

int main() {
    ll n,q,input[100005],x,i,m,ans,y;
    /// input array
    read(n);
    nfr(i,0,n){
        read(input[i]);
    }
    /// calculation of all the powers of 2
    pow2[0] = 1;
    fr(i,1,62){
        pow2[i] = pow2[i-1] * 2;
    }
    /// query
    read(q);
    fr(i,1,q){
        read(m);                /// m is the position number
        ans = 0;
        /// element are appended to the end with an amount of (power of 2)
        while(1){
            if(m == 0){         /// series starts with 1 from position 0. Here we break
                ans += 1;
                ans %= mod;
                break;
            }
            ans += input[m%n];      /// we perform the operation according to the equation
            ans %= mod;
            m = m  - bsearch(m);    ///
        }
        pf("%lld\n",ans);
    }
    return 0;
}
