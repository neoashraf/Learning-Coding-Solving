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

/// It shows how to set ,reset or toggle a bit

int main() {
    int i,x,n,k;
    read2(n,k);
    /// Set the bit
    /// the formula x | (1 << k) sets the kth bit of x to one.
    /// in 1<<k the kth bit is 1(The result of kth bit depends on this bit - as we will do OR)  and rest are 0.
    /// When | is performed kth bit of x gets 1((anything  OR 1) = 1) and rest remains the same( (anything  OR 0) = anything).
    x = n;
    x = x | (1<<k);
    cout<<"Set"<<endl;
    cout<<n<<" becomes "<<x<<endl;
    /// Reset the bit
    /// the formula x & ~(1 << k) sets the kth bit of x to zero
    /// it makes bits (k-1 to 0) 1. So the result is (1<<k) - 1
    /// in ~(1<<k) the kth bit is 0(The result of kth bit depends on this bit - as we will do AND)  and rest are 1.
    /// When & is performed kth bit of x gets 0((anything  AND 0) = 0) and rest remains the same( (anything  AND 1) = anything).
    x = n;
    x = x & ~(1<<k);
    cout<<"Reset"<<endl;
    cout<<n<<" becomes "<<x<<endl;
    /// Toggle the bit
    /// the formula x ^ (1 << k) inverts the kth bit of x.
    /// in 1<<k the kth bit is 1(The result of kth bit depends on this bit - as we will do XOR)  and rest are 0.
    /// When ^ is performed kth bit of x gets inverted(0^1->1 or 1^1->0) and rest remains the same( (anything  XOR 0) = anything).
    x = n;
    x = x ^ (1<<k);
    cout<<"Toggle"<<endl;
    cout<<n<<" becomes "<<x<<endl;
    return 0;
}

/// Test Case :
/*
Input :
7
Output :
7
3
3
**/
