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

/// given a Graph and m colour.
/// Now check if the graph can be coloured with m(1 to m) colour with no two adjacent nodes coloured same. If can print one the painted version.
/// funny fact graph with self-loop is never possible to colour under this constraint
int Graph_Matrix[10][10],m,color[10],node;

/// finds colour for each node if possible fighting with the constraint
int getnodeColor(int k){

    int i;

    while(1){                                       /// infinite loop not a issue - in the calling function we return at k == node
        color[k] = (color[k]+1) % (m+1);            /// nice modular trick to increase the colour values 0 means colour finished
        if(color[k] == 0)                           /// returns false when as colour  not found
            return color[k];
        nfr(i,0,node){
            if(Graph_Matrix[k][i] == 1 && color[k] == color[i] )     /// constraint check - adjacent nodes can not be coloured same
                break;
        }
        if(i == node)                               /// now for node k no adjacent node is coloured with color[k] so return the colour
            return color[k];
    }

}

/// sends the nodes to be coloured
int mColoring(int k){

    if(k == node)                              /// base case - solution found
        return 1;
    else{
        color[k] = getnodeColor(k);         /// call to find colour for the node k
        if(color[k] == 0)                   /// returns false when kth node can not be coloured - no solution found
            return 0;
        else
            return mColoring(k+1);          /// proceeds to the next node
    }

}

int main() {

    int i,j;
    /// Adjacency Matrix input
    read2(node,m);                  /// m colour
    nfr(i,0,node){
        nfr(j,0,node){
            read(Graph_Matrix[i][j]);
        }
    }
    mem(color,0);                   /// reset the colour
    /// initialize the Colouring procedure
    if(mColoring(0)){
        pf("Node Colours : \n");    /// print
        nfr(i,0,node){
            pf("%d\n",color[i]);
        }
        pf("\n");
    }
    else
        pf("Not Possible\n");       /// print

    return 0;
}

///input
//6 90
//0 1 1 0 0 0
//1 0 1 1 1 1
//1 1 0 1 1 1
//0 1 1 0 1 0
//0 1 1 1 0 1
//0 1 1 0 1 0
//
//4 7
//0 1 1 1
//1 0 1 1
//1 1 0 1
//0 1 0 0
//
//3 2
//0 1 1
//1 0 0
//1 0 0

