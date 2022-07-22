#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int MAX = 2e5 + 5;
int t, n, cnt1[MAX], cnt2[MAX], a[MAX], ans[MAX];
//作2个桶一加一减 求区间mex

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t c1 = clock();
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  cin >> t;
  while (t--) {
    cin >> n;
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
    memset(a, 0, sizeof a);
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt1[a[i]]++;
    }
    int len = 0;
    vector<int> vec;               //当前元素 用于清空cnt2
    int MEX = 0; 
    for (int i = 1; i <= n; i++) {  //动态维护
      vec.push_back(a[i]);
      cnt2[a[i]]++;  //当前
      cnt1[a[i]]--;  //剩余
      while(cnt2[MEX])MEX++;//求得MEX
      if (!cnt1[MEX]) {  //*****如果剩余没有mex,则其mex<=MEX,故产生一个答案
        ans[++len] = MEX;
        for (int j=0;j<vec.size();j++) {  //清空桶
          cnt2[j] = 0;
          MEX=0;//优化  只有当一次操作后再清零
        }
        vec.clear();
      }
    }
    cout << len << endl;
    for (int i = 1; i <= len; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
