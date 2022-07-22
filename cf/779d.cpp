#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;

//D1 发现从0开始的排列 前缀中0的个数大于等于一的个数
// 所以当0小于一是 x这一位取1 （01互换-）
//  想不到 555
int T, n, a[N];
int l,r;
int bit[25];
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
    memset(bit,0,sizeof bit);
    cin>>l>>r;
    int len=r+1;
    for(int i=1;i<=len;i++){
      cin>>a[i];
      int t=a[i];
     for(int j=0;j<=20;j++){
        if((t>>j)&1)bit[j]++;
     }
    }
    int ans=0,temp=1;
    for(int i=0;i<=20;i++){
      if(bit[i]>len/2)ans+=1<<i;
    }

    cout<<ans<<endl;



  }
  return 0;
}
