#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 3e5 + 5;
int c[N],d[N],h[N],C,D[N],H[N],m;
int mx[1000005];  // 价格对应的 h*d最大值
// 选择性价比高的
// 相同价格  d[i]*h[i]越大越好   （死前能造成） h[i]*d[i]/D  的伤害
//然后按照比例更新其他价格的最大值
int T, n, a[N];
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


      cin>>n>>C;
    //memset(mx,0,sizeof mx);
    for(int i=1;i<=n;i++){
        cin>>c[i]>>d[i]>>h[i];
        mx[c[i]]=max(mx[c[i]],d[i]*h[i]);
    }
    for(int i=1;i<=C;i++){
            for(int j=1;j*i<=C;j++){
                mx[i*j]=max(mx[j*i],j*mx[i]);// 倍数更新更新价格对应性价比最大值  同一种可以一起攻击
            }
    }
    for(int i=1;i<=C;i++){
        if(mx[i-1]>mx[i])mx[i]=mx[i-1];  // 花更多钱而效果更差显然不行
        // 所以用价格小的更新大的 花更多钱显然效果不能更差
    }

    cin>>m;
    for(int i=1;i<=m;i++){
            cin>>D[i]>>H[i];
            int flag=0;
            int pos=upper_bound(mx+1,mx+1+C,D[i]*H[i])-mx;  //严格大于
            // 找不到返回end() C+1
            if(pos>C)cout<<"-1"<<endl;
            else cout<<pos<<" ";
    }
    
  
  return 0;
}
