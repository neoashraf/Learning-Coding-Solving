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
#define     read(a)    scanf("%d",&a)
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

/// It checks if the input is power of 2.

/// Explanation :
/// A 2^k has a bit 1 is kth position rest (k-1 to 0) are zero. So 2^k -1 will have kth bit as 0 and (k-1 to 0) as 1.
/// Now the number x if it is no be divisible by 2^k it must be at least 2^k or other multiples.
/// So this number will have 1 in positions >= k and and rest (k-1 to 0) are zero.
/// The & operation yields to 0.

/// Examples :
/// 16 = 10000 & operation
/// 7 =  00111            /// 2^3 -1  /// k = 3
/// 0  = 00000

/// 24 = 11000 & operation
/// 7 =  00111            /// 2^3 -1  /// k = 3
/// 0  = 00000

int main() {
    int x,divisor;
    read(x,k);                              /// k to calculate the 2^k-1
    divisor = (1<<k) - 1;
    if( x & divisor == 0 )
        cout<<x<<" is a power of 2."<<endl;
    else
        cout<<"It's not."<<endl;
    return 0;
}
