
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
#define     primeLimit  50
#define     eps  1e-9
#define     mod  1000000007
#define     PI   2.0*acos(0.0)
#define     imax 2147483647
#define     lmax 9223372036854775807LL

bool check[primeLimit],ns[20];
vector<int>ans;

void sieve(void){
    int i,j;
    for(i=4;i<primeLimit;i+=2)
        check[i]=1;
    for(i=3;i*i<=primeLimit;i+=2){
      for(j=2;i*j<=primeLimit;j++)
        check[i*j]=1;
    }
    check[1]=0;
}

void make_ring(int sum,int a,int n){
    int i;
    if(ans.size() == n && check[ans[n-1] + 1]==0 ){
        for(i = 0;i<n;i++){
            pf("%d%c",ans[i],i==n-1?'\n':' ');

        }
    }

    for(i = 2;i <= n ; i++){
        if(ns[i]==0 && check[sum+i]==0){
            ans.PB(i);
            ns[i] = 1;
            sum = i;
            make_ring(sum,i,n);
            ans.POB();
            ns[i] = 0;
            sum = a;
        }
    }

}

int main() {
    sieve();
    int n,ncase=0;
    while(read(n)!=EOF){
        mem(ns,0);
        ans.clear();
        if(ncase)
            pf("\n");
        pf("Case %d:\n",++ncase);
        ans.PB(1);
        make_ring(1,1,n);
    }
    return 0;
}
