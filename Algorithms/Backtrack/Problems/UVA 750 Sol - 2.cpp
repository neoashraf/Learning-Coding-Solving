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
/// QueenPos stores the row where queen is per column

int cnt, QueenPos[100],r,c;

bool place(int k,int i){
    int j;
    fr(j,1,k-1){
        if(QueenPos[j] == i)
            return false;
        else if( abs(QueenPos[j] - i) == abs(j - k) )
            return false;
    }
    return true;
}

int NQueens(int y){
    int x,i;
    if(y == 9 && QueenPos[c] == r){                                         /// prints the solution with the fixed queen
        printf("%2d      ",cnt++);
        fr(i,1,8){
            pf("%d%c",QueenPos[i],i == 8 ? '\n' : ' ');
        }
    }
    else{
        fr(x,1,8){
            if(place(y,x)){
                QueenPos[y] = x;
                NQueens(y+1);
            }
        }
    }
}

int main() {

    int tc;
    read(tc);
    while(tc--){
        read2(r,c);
        cnt = 1;
        /// print the headings
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        NQueens(1);                                    /// beginning of the action
        if(tc)
            pf("\n");
    }
    return 0;

}
