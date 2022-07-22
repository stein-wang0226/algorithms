#include <bits/stdc++.h>
#define LOCAL
using namespace std;
set<int> S[35];
int vis[35];
int flag;
void dfs(int n) {
  vis[n]=1;        //访问标记  防止死循环
  for (auto i : S[n]) {
    if (flag) return;
    if (12 == i) {
      flag = 1;
      cout << "Yes." << endl;
      return;
    }
    if(!vis[i])dfs(i);
  }
}

int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  string a;
  while (cin >> a) {
    while (a[0] != '0') {
      int len = a.size();
      S[a[0] - 'a'].insert(a[len - 1] - 'a');
      cin >> a;
    }
    flag = 0;
    memset(vis, 0, sizeof vis);
    dfs(1);  //从b开始
    for (int i = 0; i < 30; i++) S[i].clear();
    if(!flag)cout<<"No."<<endl;
  }

  return 0;
}
