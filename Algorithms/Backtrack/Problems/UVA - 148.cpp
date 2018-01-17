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

int dic_l, phrases_l,trackP[100];
vector<string>dictionary,phrases,anagram;
string phrase_line;

int  ReadString()
{
    istringstream is(phrase_line);

    phrases = vector<string>(istream_iterator<string>(is), istream_iterator<string>());
    return 1;
}

void checkAnagram(int i,int phrase_char_l){
    int match = 0,cnt,j,l;
    if(phrase_char_l == 0){
        cout<<phrase_line<<" =";
        int ll = anagram.size();
        nfr(j,0,ll){
            cout<<" "<<anagram[j];
        }
        cout<<endl;
        return ;
    }
    if(i == dic_l)
        return ;
    nfr(j,0,phrases_l){
        if(dictionary[i] == phrases[j]){
            match = 1;
            break;
        }
    }
    if(match==0){
        l = dictionary[i].length();
        map<char,int> trackD;
        nfr(j,0,l){
            trackD[dictionary[i][j] ] ++;
        }
        l = trackD.size();
        cnt = 0;
        for (map<char,int>::iterator it=trackD.begin(); it!=trackD.end(); ++it){
            if(it->second <= trackP[ it->first ] )
                cnt++;
        }
        if(cnt == l){
            for (map<char,int>::iterator it=trackD.begin(); it!=trackD.end(); ++it){
                trackP[it->first] -= it->second;
                phrase_char_l -= it->second;
            }
            anagram.PB(dictionary[i]);
            checkAnagram(i+1,phrase_char_l);
            anagram.POB();
            for (map<char,int>::iterator it=trackD.begin(); it!=trackD.end(); ++it){
                trackP[it->first] += it->second;
                phrase_char_l += it->second;
            }
        }
        checkAnagram(i+1,phrase_char_l);
    }

}

int main() {
    int i,j,b,phrase_char_l;
    string x,blankLine;

    dictionary.clear();
    while(1){
        cin>>x;
        if(x=="#")
            break;
        dictionary.PB(x);
    }
    dic_l = dictionary.size();
    getline(cin, blankLine);
    while(1){
        getline(cin,phrase_line);
        phrases.clear();
        anagram.clear();
        mem(trackP,0);
        if(phrase_line == "#")
            break;
        ReadString();
        phrases_l = phrases.size();
        phrase_char_l = 0;
        nfr(i,0,phrases_l){
            int l = phrases[i].length();
            nfr(j,0,l){
                trackP[ phrases[i][j] ]++;
            }
            phrase_char_l += l;
        }
        checkAnagram(0,phrase_char_l);

    }
    return 0;
}
