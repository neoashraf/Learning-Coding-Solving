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

/// finds path from the top left(0,0) to bottom right(n-1,n-1)
/// so we move right and downward

int n,cnt,Map[10][10],sol[10][10];

bool isPossilbe(int i,int j);
bool findApath(int i,int j);

int main() {

    int i,j;

    while(~read(n)){

        nfr(i,0,n){
            nfr(j,0,n){
                read(Map[i][j]);
            }
        }
        cnt = 0;
        mem(sol,0);                   /// sol clear

        /// prints the grid with possible paths
        if(findApath(0,0)){           /// it is guaranteed that top left has 1
            pf("Paths :(%d in total)\n",cnt);
            nfr(i,0,n){
                nfr(j,0,n){
                    pf("%d ",sol[i][j]);
                }
                pf("\n");
            }
        }
        else
            pf("No Path lies.");
        pf("\n");

    }

    return 0;
}

bool isPossilbe(int i,int j){

    if(i >= 0 && i< n && j >= 0 && j< n && Map[i][j] == 1)
        return true;

    return false;

}

bool findApath(int i,int j){

    if(i == n-1 && j == n-1){                  /// as it is guaranteed that bottom right has 1
        cnt ++;
        sol[i][j] = 1;
        return true;
    }
    if(isPossilbe(i,j)){
        sol[i][j] = 1;                         /// possible to proceed through this position
        if(findApath(i+1 , j)) return true;    /// down
        if(findApath(i , j+1)) return true;    /// right
        /// as both the calls failed so position should be aborted and we are backing to the previous position (backtrack)
        sol[i][j] = 0;
        return false;
    }
    return false;                              /// not possible to proceed through this position so backtrack

}



///input
//4
//1 0 0 1
//1 0 0 1
//1 1 1 0
//0 0 1 1
//4
//1 1 0 0
//0 1 1 0
//0 0 1 1
//0 0 0 1
//4
//1 1 0 0
//0 1 1 0
//0 0 1 1
//0 0 1 1   //it has 2 paths
//4
//1 0 0 0
//0 0 0 0
//0 0 1 0
//0 0 0 0
