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

bool taken[5];
int input[5],permutation_[5],is23;
/// + 0 - 1 *2

int make23(int k,int is23){

    int check = -1;
    if(k == 5 && is23 == 23){
        return 1;
    }
    else if( k < 5){
        for( int i = 0; i < 3; i++ ){
            /// do the values
            if(i == 0)
                is23 += permutation_[k];
            else if(i == 1)
                is23 -= permutation_[k];
            else
                is23 *= permutation_[k];
            /// recursive call to place the operators in the four gaps
            /// this check says that we got one 23 so no further call needed
            check = make23(k+1,is23);
            if(check == 1){
                break;
            }
            ///undo
            if(i == 0)
                is23 -= permutation_[k];
            else if(i == 1)
                is23 += permutation_[k];
            else
                is23 /= permutation_[k];
        }
    }
    return check;    ///it is for per level updating so that we can break

}

int permutation(int j){

    int i,check = -1,fcheck = -1;
    if(j == 5){
        check = make23(1,permutation_[0]);   ///function call to start placement of the operators in the four gaps
        return check;
    }
    else if(check == -1){
        fr(i,0,4){
            if(taken[i])
                continue;
            taken[i] = 1;
            permutation_[j] = input[i];
            fcheck = permutation(j+1);
            if(fcheck == 1)
                break;
            taken[i] = 0;   ///it is for per level updating so that we can break
        }
    }
    return fcheck;

}

int main() {

    int i,check = -1;
    while(read(input[0]) && input[0]){
        fr(i,1,4)
            read(input[i]);
        mem(taken,0);
        check = permutation(0);
        if(check == 1)
            pf("Possible\n");
        else
            pf("Impossible\n");
    }

    return 0;
}
