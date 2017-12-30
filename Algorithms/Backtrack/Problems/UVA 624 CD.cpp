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

vector<int>taken,temp;
int N,numberOfTrack,max_,input[100];

/// recursive function
int maximizeTheSum_withinRange(int i,int sum){

    if(temp.size() > 0 && sum > N ){
        /// as an extra one is included
        if(sum - *(temp.end() - 1) > max_){
            max_ = sum - *(temp.end() - 1);
            taken = temp;
            taken.POB();   ///removes the last extra element
        }
    }
    else if(i == numberOfTrack){
        if(sum > max_){
            max_ = sum;
            taken = temp;
        }
    }
    else{
        /// taking
        temp.PB(input[i]);
        sum += input[i];
        maximizeTheSum_withinRange(i+1,sum);
        /// done now pop_back
        temp.POB();
        sum -= input[i];
        /// not taking
        maximizeTheSum_withinRange(i+1,sum);
    }

}

int main() {

    int i;
    while(~read(N)){
        read(numberOfTrack);
        max_ = -1;
        temp.clear();
        nfr(i,0,numberOfTrack){
            read(input[i]);
        }
        maximizeTheSum_withinRange(0,0);
        int l = taken.size()-1;
        fr(i,0,l)
            pf("%d ",taken[i]);
        pf("sum:%d\n",max_);
    }

    return 0;
}
