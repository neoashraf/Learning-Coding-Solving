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

template <typename T> T gcd(T a,T b) {
    return (b != 0 ? gcd(b, a%b) : a);
}
template <typename T> T modulo_cross(T a){
    return ( a % mod  * ( a + 1 ) % mod ) % mod ;
}
template <typename T> T lcm(T a, T b) {
    return (a/gcd(a,b)*b);
}
template <typename T> T BigMod (T b,T p,T m) {
    if (p == 0)return 1;
    if (p%2 == 0) {
        ll s = BigMod(b,p/2,m)%m;
        return (s*s)%m;
    }
    ll sm=((b%m)*(BigMod(b,p-1,m)%m))%m;
    return sm;
}
template <typename T> T ModInv (T b,T m) {
    return BigMod(b,m-2,m);
}
template <typename T> T POW(T B,T P) {
    if(P==0) return 1;
    if(P&1) return B*POW(B,P-1);
    else return SQR(POW(B,P/2));
}
template <typename T> T Swap(T &a,T &b) {
    T tmp=a;
    a=b;
    b=tmp;
}
int Set(int N,int pos) {
    return N=N|(1<<pos);
}
int Reset(int N,int pos) {
    return N=N&~(1<<pos);
}
bool Check(int N,int pos) {
    return (bool)(N&(1<<pos));
}
double DEG(double x) {
    return (180.0*x)/(PI);
}
double RAD(double x) {
    return (x*(double)PI)/(180.0);
}
int toInt(string s) {
    int sm;
    stringstream ss(s);
    ss>>sm;
    return sm;
}
template<class T>inline bool readfast(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
//snwe
int R[]= {0, 0,-1,1, 1,-1,-1, 1};
int C[]= {1,-1,0 ,0, 1,-1, 1,-1}; //move in 8 direction
int KR[]= {-2,-2,-1,1,2,2,-1,1};
int KC[]= {1,-1,2,2,1,-1,-2,-2}; //move of knight

/*****************************Sieve**************************
int prime_numbers[80000], total_prime=0;
bool check[primeLimit];

void sieve(void){
    int i,j;
    for(i=4;i<primeLimit;i+=2)
        check[i]=1;
    for(i=3;i*i<=primeLimit;i+=2){
      for(j=2;i*j<=primeLimit;j++)
        check[i*j]=1;
    }
    check[0]=1;
    check[1]=1;
    prime_numbers[0]=2;
    total_prime=1;
    for(i=3;i<primeLimit;i+=2){
        if(!check[i]){
            prime_numbers[total_prime++]=i;
        }
    }
}
/*******************************************************/
struct P {
    double x,y;
    P(double x=0.0, double y=0.0) {
        this ->x=x;
        this ->y=y;
    }
};
P mkv(P ae,P be) {
    return P(be.x-ae.x,be.y-ae.y);
}
double dtp(P ae,P be) {
    return (ae.x*be.x+ae.y*be.y);
}
double crp(P ae,P be) {
    return (ae.x*be.y-ae.y*be.x);
}
double val(P ae) {
    return sqrt(dtp(ae,ae));
}
P vresize(P ae,double llen) {
    double v=val(ae);
    return P(ae.x*llen/v,ae.y*llen/v);
}
double ART(P ae,P be) {
    return crp(ae,be)/2.0;
}
P rot(P ae,double ang) {
    return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));
}

/*****************************Code start from here**************************/

struct st {
    ll a,b,c,idx;
    st(ll a,ll b,ll c,ll idx) {
        this->a=a;
        this->b=b;
        this->c=c;
        this->idx=idx;
    }
};
vector<st>V;
bool cmp(st a,st b) {
    if(a.a==b.a) {
        if(a.b==b.b)
            return a.c<b.c;
        else
            return a.b<b.b;
    } else
        return a.a<b.a;
}

/// prints the subsets of elements(0,1,2,...n-1)
/// this code can accept n = 32 at best

int main() {
    int n;
    read(n);
    for (int b = 0; b < (1<<n); b++) {
    /// process subset of b
        for (int i = 0; i < 32; i++) {
            if (b&(1<<i)) cout << i << " ";
        }
            cout<<endl;
    }
    return 0;
}
