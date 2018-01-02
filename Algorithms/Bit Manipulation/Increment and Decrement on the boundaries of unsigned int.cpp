#include<bits/stdc++.h>
using namespace std;

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

/// It shows the increment ans decrement operation on boundary values of unsigned integer limit

int main() {

    unsigned int x;

    /// increment on the upper bound of unsigned integer
    x = 4294967295;                     /// 2^32 -1   upper limit
    cout << x << "\n";                  /// 4294967253
    x++;
    cout << x << "\n";                  /// 0
    /// the explanation :
    /// Here an overflow occurs. Because 4294967253 is the last value in the unsigned integer limit. It has all 1.
    /// When it increments 33th gets 1 and rest 32 bits becomes all 0.
    /// As first 32 bit forms the result so it is zero.


    /// decrement on the lower value of unsigned integer
    x = 0;                              /// lower limit
    cout << x << "\n";                  /// 0
    x--;
    cout << x << "\n";                  /// 4294967253
    /// the explanation :
    /// x is unsigned integer (It can not be -1). If we think about circular iteration 4294967295 is the previous of 0.

    return 0;
}
