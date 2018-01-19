#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("output.txt","w",stdout);
//    freopen("input.txt","r",stdin);
    int random_integer , i = 1;
    srand((unsigned)time(0));
    while(i<=10000){
        random_integer = rand();
        cout << random_integer << endl;
        i++;
    }
}
