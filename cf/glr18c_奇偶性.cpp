#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;

int T, n, a[N];
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
//给定1个01串 每次选中一个1保留其余变换  问串a到b的最小次数
// 不同的位变奇数次 相同的偶数次
// 同一位不需要被选中2次
//所以选的都是Ab相同的或都是不同的
//若可以 则被选的位01个数相差《=1 且满足变换次数奇偶性
  cin >> T;
  while (T--) {
      cin>>n;
      string a,b;
        cin>>a>>b;
        int cnt1=0,cnt0=0; //相同个数
        int cnt11=0,cnt01=0,cnt00=0,cnt10=0; //相同中0的个数
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){
                cnt1++;
                if(a[i]=='1')cnt11++;
                else cnt10++;
            }
            else{
                cnt0++;
                if(a[i]=='1')cnt01++;
                else cnt00++;
            }
        }
//1. 选相同
    int ans1=0x3f3f3f3f;

        if(cnt1%2==1&&cnt11>=cnt10&&cnt10>=cnt11-1){  //变换奇数次 自身偶数次 （不变）
           ans1=cnt1;
    }
    int ans2=0x3f3f3f3f;
    if(cnt0%2==0&&cnt01>=cnt00&&cnt00>=cnt01-1){
        ans2=cnt0;
    }
int ans=min(ans1,ans2);
if(ans==0x3f3f3f3f)cout<< -1<<endl;
else cout<<ans<<endl;
  }
  return 0;
}
