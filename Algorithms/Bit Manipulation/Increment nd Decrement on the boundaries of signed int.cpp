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

/// It shows the increment ans decrement operation on boundary values of signed integer limit

int main() {

    int x;

    /// increment on the upper bound of signed integer
    x = 2147483647;                     /// 2^31 -1   upper limit
    cout << x << "\n";                  /// 2147483647
    x++;
    cout << x << "\n";                  /// -2147483648
    /// the explanation :
    /// Here an overflow occurs. Because 2147483647 is the last positive value in the signed integer limit, can not move further right. But it is moving.
    /// What it gets -- a negative value. Why ?
    /// The reason is 2147483647 is a positive one and the highest in the 31 bit limit. So it has 32th bit 0 and rest(31 - 0) as zero.
    /// As it increments it becomes 2147483648. That is 32th bit gets 1 and rests are zero. It is the first number in the 32th bit position.
    /// As 32th bit(sign bit) is 1, it outputs negative 2147483648. 2147483648 has a twos complement that is same to its binary.
    /// Power position twos complement are same as there binary
    /// It shows us that the next element of 2147483647 in signed integer is -2147483648



    /// decrement on the lower value of signed integer
    x = -2147483648;                    /// -2^31    lower limit
    cout << x << "\n";                  /// -2147483648
    x--;
    cout << x << "\n";                  /// 2147483647
    /// The reverse situation of the above one.
    /// -2147483648 (32-0) all bits are 1.
    /// As it decrements it goes to its previous value 2147483647 that has (32 bit-0)(31-0) are 1s. That is the last positive number. in the signed integer.

    return 0;

}
