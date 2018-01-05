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

/// This code shows the basic for set operations

int main() {
    int x , y,z;
    /// Here x and y represents two sets by the bit 1s in their binary representation
    x = (1<<2) + (1<<21) + (1<<4) + (1<<6) + (1<<7) ;
    y = (1<<2) + (1<<12) + (1<<25) + (1<<21) + (1<<4) ;
    /// Intersection
    z = x&y;
    cout<<__builtin_popcount(z)<<endl;      /// prints the number of common elements
    /// Union
    z = x|y;
    cout<<__builtin_popcount(z)<<endl;      /// prints the total unique elements in the both sets
    /// Complement
    z = ~x;
    cout<<__builtin_popcount(z)<<endl;      /// counts the elements not in x
    /// Difference
    z = x&(~y);
    cout<<__builtin_popcount(z)<<endl;      /// prints the elements in x but not in y. to do that we invert y then perform an AND.
    return 0;
}
