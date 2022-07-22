#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
#define int long long
using namespace std;

const int N = 3e5 + 5;
int T, n, a[N],d[N];
int sumd;
int check1(int mid){
 int even=mid/2;int odd=mid-even;
            int cnt2=0;
            for(int i=1;i<=n;i++){
                cnt2+=d[i]/2;  //可用的2的总数
            }
        int used=min(cnt2,even);
        if(odd>=sumd-used*2)return 1;//剩下用1   奇数天数足够

        return 0;
}

int check2(int mid){ // maxx+1的情况
 int even=mid/2;int odd=mid-even;
            int cnt2=0;
            for(int i=1;i<=n;i++){
                cnt2+=(d[i]+1)/2;  //2的个数
            }
        int used=min(cnt2,even);
        if(odd>=sumd+n-used*2)return 1;

        return 0;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  cin >> T;
  while (T--) {
      cin>>n;
      for(int i=1;i<=n;i++)cin>>a[i];
      sort(a+1,a+1+n);
       sumd=0;
        for(int i=1;i<=n;i++)d[i]=a[n]-a[i],sumd+=d[i];
      int l=0,r=sumd*2+5;
      while(l<r){
          int mid=(l+r)>>1;
         if(check1(mid))r=mid;
         else l=mid+1;
      }

    int ans0=l;
    l=0;r=sumd*5;
 while(l<r){
          int mid=(l+r)>>1;
         if(check2(mid))r=mid;
         else l=mid+1;
      }

int ans=min(ans0,l);
cout<<ans<<endl;
  }
  return 0;
}
