#include <bits/stdc++.h>
//#define LOCAL
//#define int long long
using namespace std;
const int N = 5005;
int pre[N];
int find(int x) {
  if (pre[x] != x) {
    pre[x] = find(pre[x]);
  }
  return pre[x];
}

int n;
signed main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> n;
  for (int i = 1; i <= 3*n; i++) pre[i] = i;
  map<string, int> in;
  map<string, int> out;
  map<string, int> id;
  map<int,string> ss;
  set<string> st1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    string a, b;
    cin >> a >> b;
    st1.insert(a);
    st1.insert(b);
    if (!in[a] && !out[a]) {
      id[a] = ++cnt;
      ss[cnt]=a;
    }
    if (!in[b] && !out[b]) {
      id[b] = ++cnt;
        ss[cnt]=b;
    }
    out[a]++, in[b]++;
    if (find(id[a]) != find(id[b])) {
      pre[find(id[b])] = find(id[a]);
    }
  }
  set<string> st2;
    int ans = 0;
  for (auto i : st1) {
    if (in[i] == 1 && out[i] == 0) st2.insert(i),ans++;  //为
  }
  cout<<ans<<endl;
  for(auto i:st2){
      string f=ss[find(id[i])];
      cout<<f<<" "<<i<<endl;
  }
  return 0;
}
