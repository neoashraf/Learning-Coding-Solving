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

/// Problem Statement :
/*
Given an array and a window size. Window starts from index zero and slides forward until the end.
Now report the minimum elements of the window as it slides forward.
*/
/// Solution Complexity : O(n)

/// Two Pointer :
/// One is the array iterator another is the deque pointer.

int main() {

    int i,n,input[1000],window_size,window_start,window=0;
    /// using deque as we need operation on both ends
    deque< pair<int,int> >helper;                 /// keep tracks of the minimum element in the sliding window

    /// input
    read2(n,window_size);
    nfr(i,0,n){
        read(input[i]);
    }

    /// printing format
    pf("---- Minimum in the sliding window ----\n");
    pf("\tWindow :: Value :: Index\n");

    window_start = -1;                           /// sliding window header starts at -1 for a reason
    /// we use helper a deque (pair of(value,index)) to keep track of the minimum element in the window. The front value is the answer.
    nfr(i,0,n){

        /// we push a new element in the new deque when it is greater than all others
        while(!helper.empty() && helper.back().first > input[i]){
            helper.pop_back();
        }
        helper.push_back( mkp(input[i],i) );

        /// we get the first window when i is window_size - 1 after that for every iteration a new window
        /// for every window we print the minimum
        if( i>= window_size - 1){               /// window_size - 1 for index adjustment
            /// as new window comes header goes up by 1
            /// here we get the header when the window is complete. As first window done at window_size - 1 header becomes 1
            window_start ++;
            /// sometimes the first element is part of the previous window. So that is out
            if(helper.front().second < window_start)
                helper.pop_front();

            /// print the minimum
            pf("\t%d\t%d\t%d\n",++window,helper.front().first,helper.front().second);
        }

    }
    return 0;
}

/// Test Case
/*
input
8 4
2 1 4 5 3 4 1 2
/// output
---- Minimum in the sliding window ----
        Window :: Value :: Index
        1       1       1
        2       1       1
        3       3       4
        4       1       6
        5       1       6
*/
