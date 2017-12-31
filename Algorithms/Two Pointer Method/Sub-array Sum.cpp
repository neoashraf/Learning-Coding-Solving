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

/// Given an Array -> input and a number x find a sub-array that's sum equals to x. One solution then break
/// Solution Complexity - O(n)

int main() {

    int n,input[1000],p1,p2,i,x,sum;

    /// input
    read2(n,x);
    nfr(i,0,n){
        read(input[i]);
    }

    /// two pointer p1 and p2. p1 points to the first and p2 to the last element of the sub-array.
    /// p1 makes one step to right at each turn and p2 towards right as long as sum <= x. -- it is the main theme.
    /// My implementation
    /// p1 and p2 starts at 0.
    /// p2 goes on until sum <= x. If sum == x solution is printed.
    /// When p2 fails to move, turn comes to p1. The first value of sub-array (input[p1]) is subtracted, p1 moves to right one step.

    sum = 0;                    /// sum initialize
    p1 = 0;
    p2 = 0;
    while(p1 < n){

        while(sum + input[p2]<= x ){
            sum += input[p2];
            if(sum == x){           /// solution print
                fr(i,p1,p2){
                    pf("%d ",input[i]);
                }
                pf("\n");
                return 0;
            }
            p2++;
        }

        /// as p2 failed to move right
        sum -= input[p1];    /// if p2 fails at 0 this operation will give some values to sum. This values will become neutral when p2 progresses
        p1++;

    }

    if(p1 == n)                     /// if solution is found code will end in line (sum == x) at least at n-1
        pf("No Solution\n");

    return 0;
}

/// Test Case --
/*Input
4 55
100 100 1 54

8 8
1 3 2 5 1 1 2 3

Output
1 54
2 5 1
*/
