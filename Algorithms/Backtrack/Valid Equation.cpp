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
#define     read5(a,b) scanf("%d %d %d %d %d",&a,&b,&c,&d,&e)
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

/// problem statement : Given a array of n elements (0 to n-1). Perform operations (+,-,*) on (0 to n-1) elements. Check if it equals to the n-1th
/// total combination is (number of operator)^n-2
int input[20],N;

/// forms the equation result based on the combination of operators
int makeValid(int n,int k,int result){

    if(k == n-1){
        if(result == N)
            return 1;
        else
            return 0;
    }
    else if(k <= n - 2){

        for( int i = 0; i < 3; i++ ){               /// (+)->0 (-)->1  (*)->2

            /// operation
            if(i == 0)
                result += input[k];
            else if(i == 1)
                result -= input[k];
            else
                result *= input[k];

            ///recursive call to place the operators in the four gaps
            return makeValid(n,k+1,result);               /// return the received value from down to upward

            /// undo the operation (backtracking)
            if(i == 0)
                result -= input[k];
            else if(i == 1)
                result += input[k];
            else
                result /= input[k];

        }

    }

}

int main() {

    int i,check,result,n;
    while(read(n)){
        ///input
        nfr(i,0,n)
            read(input[i]);

        N = input[n-1];                  /// RHS -> N = (n-1)th element the                LHS = operationOf(0,1,....n-2) elements
        result = input[0];              /// result is set to the first value, further operation will be in the makeValid function

        if(makeValid(n,1,result))       /// calls the Validator function and prints the result
            pf("Possible\n");
        else
            pf("Impossible\n");
    }

    return 0;
}
