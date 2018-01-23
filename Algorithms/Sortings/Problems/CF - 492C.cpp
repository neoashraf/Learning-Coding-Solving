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

struct st {
    ll a,b;
    st(ll a,ll b) {
        this->a=a;
        this->b=b;
    }
};
vector<st>V;
bool cmp(st a,st b) {
    return a.b < b.b;
}

int main() {
    ll n,r,avg,i,diff,x,y,reqTotal_grade, minEssay,gradeSum = 0;

    cread3(n,r,avg);
    fr(i,1,n){
        cread2(x,y);
        gradeSum += x;
        V.PB(st(x,y));           /// it calls the constructor st, which sets the values in struct st and the elements  are pushed back in the vector
    }

    reqTotal_grade = n * avg;
    diff = reqTotal_grade - gradeSum;
    /// grades are sufficient
    if(diff <= 0){
        pf("0\n");
        return 0;
    }
    /// grades not sufficient so grade increase is needed
    sort(all(V),cmp);                /// sort in ascending order according to essayNumber
    minEssay = 0;
    nfr(i,0,n){
        minEssay += (min(r - V[i].a,diff) * V[i].b);
        diff -= min(r - V[i].a,diff);
        if(diff <= 0){
            pf("%I64d\n",minEssay);
            return 0;
        }
    }

    return 0;
}
