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

int input[sz];           /// 10^6 elements

int main() {
    int n,i,j;
    ll cnt,ans =0;
    /// input
    read(n);
    fr(i,0,n-1){
        read(input[i]);
    }

    /// x Xor y = 0 means that x and y are the same element. So the task is to find the count of the similar numbers.
    /// that's why sort is needed
    sort(input,input+n);

    i = 0;
    ans = 0;            /// total count of desired pair
    while(i<n){
        cnt = 0;
        j = i+1;
        while(input[i]==input[j]){       /// counts the consecutive same elements
            cnt++;
            j++;
        }
        int x = (cnt * (cnt+1)) / 2;     /// cnt elements forms x pairs. for example : 3 is present 4 times , desired pair will be (1+2+3) .
        ans += x;                        /// Then add it to ans
        i = j;
    }
    pf("%lld\n",ans);
    return 0;
}
