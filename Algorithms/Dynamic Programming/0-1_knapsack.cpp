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

/// It is the basic 0/1 knapsack problem

int n,cap;

struct st{
    int p,w;
    st(int p,int w){
        this->p = p;
        this->w = w;
    }
};
vector<st>objectDetails;

int z_1_knapsack(int i,int w){
    int profit0 ,profit1;
    if(i == n)
        return 0;
    profit0 = z_1_knapsack(i+1,w);
    if(w + objectDetails[i].w <= cap)
        profit1 = objectDetails[i].p + z_1_knapsack(i+1,w+objectDetails[i].w);
    else
        profit1 = 0;
    return max(profit0,profit1);
}

int main() {
    int tc,i,x,y;
    read(tc);
    while(tc--){
        read(n);
        objectDetails.clear();
        fr(i,1,n){
            read2(x,y);
            objectDetails.PB(st(x,y));
        }
        read(cap);
        pf("%d\n",z_1_knapsack(0,0));
    }
    return 0;
}
