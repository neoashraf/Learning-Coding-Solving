5#include<bits/stdc++.h>
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

vector<string> input,digits;
string x,y;

void generateDigits(int cnt ,int n){
    int i;
    if(cnt == n){
        digits.PB(y);
        //cout<<y<<endl;
        return ;
    }
    fr(i,0,9){
        y.PB(i+'0');
        generateDigits(cnt+1,n);
        y.POB();
    }
}

int main() {
//    freopen("output.txt","w",stdout);
//    freopen("input.txt","r",stdin);

    int i,ii,j,k,q,n,m,zeros;
    while(read(n)!=EOF){
        input.clear();
        fr(i,1,n){
            cin>>x;
            input.PB(x);
        }
        cout<<"--"<<endl;
        read(m);
        fr(ii,1,m){
            cin>>x;
            j = 0;
            zeros = 0;
            while(x[j]!='\0'){
                if(x[j]=='0')
                    zeros++;
                j++;
            }
            digits.clear();
            generateDigits(0,zeros);
            int l = digits.size();
            nfr(i,0,n){
                nfr(j,0,l){
                    k = 0;
                    q = 0;
                    while(x[k]!='\0'){
                        if(x[k] == '#')
                            cout<<input[i];
                        else
                            cout<<digits[j][q++];
                        k++;
                    }
                    cout<<endl;
                }
            }

        }
    }
    return 0;
}
