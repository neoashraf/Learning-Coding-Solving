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

int main() {

    int tc,d,n,i,j,r,c,nRats,x,y,ans,killed[1500][1500],topx,topy,bottomx,bottomy;
    read(tc);
    while(tc--){
        read(d);
        read(n);
        mem(killed,0);
        /// we try to fill the array killed( killing amount of each bombing location ) by taking a area of radius d around the mouse position
        fr(i,1,n){
            read3(r,c,nRats);           /// rat position and amount input
            /// creates the boundary of rectangular area for each mouse position
            topx = max(0,x-d), topy = max(0,y-d), bottomx = min(1024,x+d), bottomy = min(1024,y+d);
            /// adds up the number of rats to all those position( bomb position ) which will cover this mouse location if a bomb is placed
            fr(x,topx,bottomx){
                fr(y,bottomy,bottomy){
                    killed[x][y] += nRats;
                }
            }
        }
        /// get first the position with maximum kill
        ans = -1;
        fr(i,0,1024){
            fr(j,0,1024){
                if(killed[i][j] > ans){
                    x = i; y = j;
                    ans = killed[i][j];
                }
            }
        }
        pf("%d %d %d\n",x,y,ans);
    }

    return 0;
}
