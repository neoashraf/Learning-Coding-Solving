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

int placementOfQueen[100], /// tracks the columns where the queen is in row 0 to n-1
    cnt = 1;

/// it checks if in column i queen can be placed  and the the row number is k
bool place(int k,int i){

    int j;
    /// we iterate over the rows where queen is already placed that is 0 to k-1 to check if in ith column the queen can be placed
    fr(j,0,k-1){
        /// this conditions checks if column position i in row k is attacked by same column or diagonal
        if( placementOfQueen[j] == i )    /// column check  /// row checked by default as we place only one pre row
            return false;
                                        /// diagonal check (x1,y1) & (x2,y2) points on diagonal then (x1-x2) == (y1-y2)
        else if( /*col diff*/abs (placementOfQueen[j] - i ) == /*row diff*/abs( j - k ) )
            return false;
    }
    /// we  can place
    return true;

}

/// forms the index of position to place a queen and call the place function, print the possible move.
void NQueens(int k,int n){

    int i;
    if(k == n){                       /// print the solution
        pf("Solution Number --> %d : ",cnt++);
        nfr(i,0,n){
            pf("%d%c", placementOfQueen[i], i == n-1 ? '\n' : ' ');
        }
    }
    nfr(i,0,n){
        if(place(k,i)){               /// check call
            placementOfQueen[k] = i;  /// assignment of the column number in row k
            NQueens(k+1,n);           /// as placed one proceed to the next row
        }
    }

}

int main() {
    int n;
    read(n);
    NQueens(0,n);
    return 0;
}
