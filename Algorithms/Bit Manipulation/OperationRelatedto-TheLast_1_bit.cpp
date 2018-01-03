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

/// the last 1 bit is the first one from the right
int main() {
    int x,n;
    read(n);

    /// The formula x & (x−1) sets the last one bit of x to zero
    /// Lets say the last 1 is in position k. (k to 0) bits represents 2^k.                               Example 8->1000
    /// this position k in x-1 is surely 0 and (k-1 to 0)bits are 1. (k-1 to 0) bits represents 2^k - 1.  Example 7->0111
    /// So AND gives position k 0 and following (k-1 to 0)bits are already 0.
    /// This means 2^k is subtracted from the number
    x = n;
    x = x & (x-1);
    cout<<n<<" becomes "<<x<<"."<<endl;

    /// The formula x | (x−1) inverts all the bits after the last one bit.
    /// Lets say the last 1 is in position k. (k to 0) bits represents 2^k.                               Example 8->1000
    /// this position k in x-1 is surely 0 and (k-1 to 0)bits are 1. (k-1 to 0) bits represents 2^k - 1.  Example 7->0111
    /// So OR gives position k 1 and the following (k-1 to 1)bits get inverted(here 0->1).
    /// This means (2^k -1) is added to the number.
    x = n;
    x = x | (x-1);
    cout<<n<<" becomes "<<x<<"."<<endl;

    /// The formula x & −x sets all the one bits to zero, except for the last one bit.
    /// -x is two's compliment of x. That is -x = ~x + 1;
    /// Lets say the last 1 is in position k. (k to 0) bits represents 2^k.                              Example 8->1000
    /// this position k in ~x is surely 0 and (k-1 to 0)bits are 1. (k-1 to 0) bits represents 2^k - 1.  Example 7->0111  +1
    /// For the + 1 operation in -x the k-th bit gets 1 and the (k-1 to 0)bits get 0.                               1000
    /// So the x & -x gives kth bit 1. But resets all other 1's before and after k.
    /// That is the number becomes 2^k
    x = n;
    x = x & -x;
    cout<<n<<" becomes "<<x<<"."<<endl;

    return 0;
}
