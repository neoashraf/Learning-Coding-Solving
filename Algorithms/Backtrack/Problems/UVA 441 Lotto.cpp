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

int n,input[100];
bool taken[100];
vector<int>permutation_;

int printThePermutations(){

    int l = permutation_.size();
    /// the printing is limited to 6 elements
    if( l == 6 ){
        for(int j = 0 ; j < 6 ; j++)
            pf("%d%c", permutation_[j], j == 5 ? '\n':' ');
    }
    else{
        /// it is a permutation problem
        for(int j = 0; j < n ; j++){
            /// getting rid of the already taken ones
            if(taken[j])
                continue;
            /// as we always traverse from 0 to n here we have to avoid the elements (0 to j-1) for any index j
            if( l > 0 && permutation_[l-1] > input[j] )
                continue;
            taken[j] = 1;
            permutation_.PB(input[j]);
            printThePermutations();
            taken[j] = 0;
            permutation_.POB();
        }
    }

}

int main() {

    int i,cnt = 0;
    while(~read(n) && n){
        nfr(i,0,n){
            read(input[i]);
        }
        if(cnt)
            pf("\n");
        mem(taken,0);
        cnt++;
        printThePermutations();
    }

    return 0;
}
