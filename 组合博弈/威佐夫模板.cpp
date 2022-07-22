#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstring>
#include<cmath>
#define LOCAL
using namespace std;
//威佐夫博弈模板
const double q=(sqrt(5.0)+1.0)/2.0;
int main()
{
long long m,n,k;
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
  cin>>m>>n;
  if (m > n) {
    long long t = m;
    m = n;
    n = t;
  }  // swap
  k=n-m;
  if(m==int(q*double(k)))cout<<"0";//是奇异局势，后手胜利
  else cout<<"1";//先手win
    return 0;
}
