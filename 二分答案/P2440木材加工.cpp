#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int Max =1e5+5;
long long  n,k,L[Max],Sum=0,r,l,m;
int check(int mid){
  int sum=0;//sum记录木块总数, m->max
    for(int i=1;i<=n;i++){
        sum+=L[i]/mid;
    }
    if(sum>=k)return 1;//*******大于也满足区间*******  不能是==
    else return 0;
}
int main() {//求最小最大值 ，模板1；
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> n >> k;
  m=0;//, m->max
  for(int i=1;i<=n;i++){//input
    cin>>L[i];
    Sum+=L[i];
     if(L[i]>m)m=L[i];
  }
  if(k>Sum){//特判长度为1都达不到k的情况
      cout<<0;return 0;
  }
  l=1;r=m;
  while(l<r){//二分模板
     int  mid=(l+r+1)>>1;
      if(check(mid)){
        l=mid;
      }
      else r=mid-1;
  }
  cout<<l;
  return 0;
}