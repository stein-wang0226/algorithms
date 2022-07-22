#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e6 + 5;
int T, n, a[N],b[N];
//区间整体 加一 减一  差分数组两个单点加  两端一加一减
// 若全部相等 则差分数组除b[1]全为0
// 对b数组>1部分 正数负数分别求和sum1,sum2（绝对值）的最大值即可  （消为全*/-后，再做延伸到两端的区间+/-）  
//下面 对于种类
// 最后的财富 即最后a[1]的值 消为全正或全负后 剩下的可以向头（a[1]）加也可以向后
//所以共abs(sum1-sum2)+1种 
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    //构造差分数组
    b[1]=a[1];
    for(int i=2;i<=n;i++)b[i]=a[i]-a[i-1];
    int sum1=0,sum2=0;
    for(int i=2;i<=n;i++){
        if(b[i]>0)sum1+=b[i];
        else sum2-=b[i];
    }
    int ans=max(sum1,sum2);
    int num=abs(sum1-sum2)+1;
    cout<<ans<<endl;
    cout<<num<<endl;

}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

      solve();
  
  return 0;
}
