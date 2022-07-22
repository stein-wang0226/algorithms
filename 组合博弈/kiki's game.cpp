#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstring>
//#define LOCAL
using namespace std;
int m,n;
int a[1005];
int main()
{
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    while(cin>>n>>m,m*n){//分析必胜必败点，--偶数行 必胜，只有奇数行奇数列时必败
        if(n%2&&m%2)cout<<"What a pity!"<<endl;
        else
          cout << "Wonderful!"<<endl;
    } 
    return 0;
}
