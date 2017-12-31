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

/// Problem statement
/*
Given an array of n numbers and a target sum x,
find two array values such that their sum is x, or report that no such values exist.
*/
/// Solution Complexity - O(n log(n))

int main() {

    int input[1000],p1,p2,n,x,i,sum;

    /// input
    read2(n,x);
    nfr(i,0,n){
        read(input[i]);
    }

    /// sorting helps when we iterate using the two pointers
    sort(input,input+n);

    /// two pointers p1 and p2. p1 and p2 points to the first and second element of the answer respectively
    /// p1 move to right while p2 to left
    p1 = 0;
    p2 = n-1;

    /// we will find the solution if it exists before p1 =s p2
    while(p1 < p2){

        sum = input[p1] + input[p2];      /// sum

        /// we one of the pointer at a time depending on situation

        if( sum < x )                    /// now we need a larger value and that will be the left one as right one is the largest possible  (sorted array)
            p1++;
        else if(sum > x)                /// now we need a smaller value and that will be the right one as left one is the lowest possible  (sorted array)
            p2--;
        else{
            pf("%d %d\n",input[p1],input[p2]);  /// print solution
            return 0;                           /// code ends
        }

    }

    if(p1 >= p2)
        pf("Got no such two values man sorry\n");

    return 0;
}

/// Test case
/*
input
8 21
1 4 5 6 7 9 9 10
8 12
1 4 5 6 7 9 9 10
output
Got no such two values man sorry
5 7
*/
