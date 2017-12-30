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

/// this solution prints the row position of queen per column  as stated [here one queen has fixed position]

/// row tracks if any queen is placed in row x
/// as diagonal is possible in two ways , two arrays is needed to mark them. Here they tracks if any queen is in the diagonal x

int r,c,row[100],diag1[100],cnt,diag2[100],QueenPos[100];

/// places the queen per column
int placeNQueens(int y){

    int x,i;
    if(y == 9){                                         /// prints the solution
        printf("%2d      ",cnt++);
        fr(i,1,8){
            pf("%d%c",QueenPos[i],i == 8 ? '\n' : ' ');
        }
    }
    else if( y == c)                                    /// just pass when it is column c
        placeNQueens(y+1);
    else{
        fr(x,1,8){
            /// for each position in the grid there is three check
            /// one for same row , the rest two for two diagonal
            if( row[x] || diag1[x+y] || diag2[x-y+8-1] )    /// attacking position
                continue;
            /// possible position in row y
            row[x] = 1, diag1[x+y] = 1, diag2[x-y+8-1] = 1;
            QueenPos[y] = x;                                 /// store the result
            placeNQueens( y+1 );                            /// call for next column
            /// clear the arrays as one solution is found
            row[x] = 0, diag1[x+y] = 0, diag2[x-y+8-1] = 0;
        }
    }

}

int main() {

    int tc;
    read(tc);
    while(tc--){
        mem(row,0) , mem(diag1,0) , mem(diag2,0);               /// clears initially
        read2(r,c);
        cnt = 1;
        /// marked that the fuck owns this place forever
        row[r] = 1, diag1[r+c] = 1, diag2[r-c+8-1] = 1;
        QueenPos[c] = r;

        /// print the headings
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        placeNQueens(1);                                    /// beginning of the action
        if(tc)
            pf("\n");
    }
    return 0;

}
