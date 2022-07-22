#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N = 3e5 + 5;
int a[N], s[N];  // 结果  ，前缀和
typedef pair<int, int> PII;
vector<int> alls;  //全部元素用于离散化
vector<PII> add, query;
int m, n;
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
cin>>n>>m;
  for (int i = 1; i <= n; i++) {
    int x, c;
    cin >> x >> c;
    add.push_back({x, c});
    alls.push_back(x);           //alls 储存所有x值 离散化后 处理
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    query.push_back({l, r});
    alls.push_back(l);  //   也要进行离散化   
    alls.push_back(r);
  }

  sort(alls.begin(), alls.end());//
  int len = unique(alls.begin(), alls.end()) - alls.begin();//
  for (auto i : add) {
    int x = lower_bound(alls.begin(), alls.end(), i.first) - alls.begin() +1;  //离散化后位置从1开始
    a[x]+=i.second;//
  }
  for(int i=1;i<=alls.size();i++){
      s[i]=s[i-1]+a[i];//前缀和
  }
  for(auto i:query){
      int l =lower_bound(alls.begin(),alls.end(),i.first)-alls.begin() +1;
     int r =lower_bound(alls.begin(),alls.end(),i.second)-alls.begin() +1;
    cout<<s[r]-s[l-1]<<endl;
  }
  return 0;
}
