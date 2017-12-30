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
#define     write(a)   printf("%d",a)
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

int n,l;
string subset_;
string x;
bool taken[37];

void subset(){
    if(subset_.length() == n){
        cout<<subset_<<endl;
        return ;
    }
    else{
        for(int i = 0 ; i<l ; i++){
            /// as we always traverse from 0 to n here we have to avoid the elements (0 to j-1) for any index j
            if(subset_.length() > 0 && subset_[ subset_.length()-1 ] > x[i] )
                continue;
            if(taken[i] == 0){
                subset_.PB(x[i]);
                taken[i] = 1;
                subset();
                taken[i] = 0;
                subset_.POB();
                /// avoid the repeated characters
                while(x[i]==x[i+1] && i+1 < l )i++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int i;
    while(cin>>x>>n){
        sort(all(x));
        l = x.length();
        mem(taken,0);
        subset();
    }
    return 0;
}
