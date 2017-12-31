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

/*
There are people sitting in a circular fashion,
print every third member while removing them,
the next counter starts immediately after the member is removed.
Print till all the members are exhausted.
For example:
Input: consider 123456789 members sitting in a circular fashion,
Output: 369485271
*/

vector<int>input;
int jump,pos,n;
/// prints the element by a jump of j and the taken one is removed
int josepheus (){

    int i,l;
    pos = 0;
    l =input.size();
    while(1){
        /// all cleared
        if(l == 0)
            return 1;
        /// when one item in pos i is deleted
        /// the next items shifts left so the jump is made from pos i
        pos += jump ;                         /// value increases by 3
        pos = (pos % l)? (pos%l) : l;         /// if we get a remainder that is the pos or the last element(size)
        pos--;                                /// adjust  the array index
        pf("%d ",input[pos]);                 /// print the element
        input.erase(input.begin()+ pos);      /// delete item --deletes the element in index pos (that is pos+1 th element)
        l--;                                  /// size shrinks
    }

}

int main() {

    int x,i;
    read2(n,jump);
    fr(i,1,n){
        read(x);
        input.PB(x);
    }
    josepheus();

    return 0;
}
