
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

/// col tracks if any queen is placed in column x
/// as diagonal is possible in two ways , two arrays is needed to mark them. Here they tracks if any queen is in the diagonal x

int n,col[100],diag1[100],diag2[100],cnt=0;
vector<int>QueenPos;                                    /// prints columns per row
int board[15][15]={0};

/// places the queen per row
int placeNQueens(int y){

    int x,i;
    if(y == n){                                         /// solution found
        ++cnt;                                          /// counts the solutions
        if(cnt == 1){                                   /// places the queens in the board according to the first solution
            nfr(i,0,n){
                board[i] [QueenPos[i] ] = 1;
            }
        }
        return 0;
    }
    nfr(x,0,n){
        /// for each position in the grid there is three check
        /// one for same column , the rest two for two diagonal
        if( col[x] || diag1[x+y] || diag2[x-y+n-1] )    /// attacking position
            continue;
        /// possible position in row y
        col[x] = 1, diag1[x+y] = 1, diag2[x-y+n-1] = 1;
        QueenPos.PB(x);                                 /// push the result
        placeNQueens( y+1 );                            /// call for next row
        /// calculation
        col[x] = 0, diag1[x+y] = 0, diag2[x-y+n-1] = 0;
        QueenPos.POB();
    }

}

int main() {

    int i,j;
    read(n);
    if(n==2 || n==3)
        pf("Not possible\n");
    else{
        mem(col,0) , mem(diag1,0) , mem(diag2,0);               /// clears initially
        QueenPos.clear();
        placeNQueens(0);                                        /// beginning of the action
        fr(i,0,n-1){                                            /// prints the first solution in the board
            fr(j,0,n-1){
                pf("%d ",board[i][j]);
            }
            pf("\n");
        }
    }

    return 0;

}
