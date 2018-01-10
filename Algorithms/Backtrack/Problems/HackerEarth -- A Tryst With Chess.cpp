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

/// 10x10 board, given the initial position of a knight after n moves in how many different cell blocks it  may go

//snwe
int R[]= {0, 0,-1,1, 1,-1,-1, 1};
int C[]= {1,-1,0 ,0, 1,-1, 1,-1}; //move in 8 direction
int KR[]= {-2,-2,-1,1,2,2,-1,1};
int KC[]= {1,-1,2,2,1,-1,-2,-2}; //move of knight

int visited[15][15],  /// records if any cell is taken or not
cnt;

void movein(int x,int y,int moveid,int n){
    int i,xx,yy;
    if(moveid == n+1){
        return ;
    }
    fr(i,0,7){                                         /// knight move
        xx = x + KR[i];
        yy = y + KC[i];
        if(xx>=1 && xx<=10 && yy>=1 && yy<=10){        /// boundary check

            if(moveid == n && !visited[xx][yy]){       /// when we are in the last move we count the new cell blocks
                visited[xx][yy] = 1;
                cnt++;
            }
            movein(xx,yy,moveid+1,n);                  /// new call
        }
    }
}

int main() {
    int x,y,n;
    mem(visited,0);                                     /// clear
    read3(x,y,n);
    cnt = 0;
    movein(x,y,1,n);                                    /// third parameter means the move number
    pf("%d\n",cnt);
    return 0;
}
