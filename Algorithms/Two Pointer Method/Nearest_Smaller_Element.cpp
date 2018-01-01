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

/// Problem Statement : Given an array find the nearest smallest elements for each array value
/// Solution Complexity : O(n)

/// Two Pointer :
/// One is the array iterator another is the stack pointer.

int main() {

    int input[1000],p1,p2,n,x,i,sum;
    stack <int> helper;

    /// input
    read(n);
    nfr(i,0,n){
        read(input[i]);
    }

    pf("Nearest smaller elements for each array value\n");

    /// uses a stack to keep track
    /// while iterating through the array for each position i the topmost element in stack is the answer
    nfr(i,0,n){
        /// to get smaller element on top we remove the larger values than the current array value from stack
        while(!helper.empty() && helper.top() >= input[i]){
            helper.pop();
        }
        pf("Position %d : ",i);
        if(helper.empty())
            pf("No nearest smaller element\n");             /// as empty nothing we get
        else
            pf("%d\n",helper.top());                        /// top is the nearest smaller element
        helper.push(input[i]);                              /// push the current element as it can be the smaller element for the upcoming elements

    }

    return 0;
}

/// Test case
/*
input
8
1 3 4 2 5 3 4 2
output
no 1 3 1 2 2 2 1
*/
