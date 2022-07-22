#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int t;
//不知道哪挂了 :(
const int MAX = 5e5 + 5;  //如果是64MB可以开到2e6+5，尽量开大
int tree[MAX][26];  // tree[i][j]表示节点i的第j个儿子的节点编号
bool flag[MAX];      //表示以该节点结尾是一个单词
int sum[MAX];
int index[10005];
int tot = 0;  //总节点数
int ans = 0;
void insert_(string s, int indexx) {
  int len = s.size();
  int root = 0;
  for (int i = 0; i < len; i++) {
    int id = s[i] - 'a';
    if (!tree[root][id]) tree[root][id] = ++tot;  //新子树 编号tot+1
    root = tree[root][id];
    if(index[root]!=indexx)sum[root]++;//编号不同
    index[root] = indexx;
  }
  if (!flag[root]) {
    flag[root] = 1;
  }  //未出现
}
int find_(string s)  //查询操作，按具体要求改动
{
  int len = s.size();
  int root = 0;
  for (int i = 0; i < len; i++) {
    int id = s[i] - 'a';
    if (!tree[root][id]) return 0;
    root = tree[root][id];
  }
  return sum[root];
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int n;
  cin >> n;
  memset(sum, 0, sizeof sum);
  memset(tree, 0, sizeof tree);
  memset(index,0,sizeof index);
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int len = s.size();
    string s1 = "";  //每个后缀
    for (int j = len - 1; j >= 0; j--) {
      s1 += s[j];
      string s2 = s1;
      reverse(s2.begin(), s2.end());
      insert_(s2, i);  //
    }
  }
  int m;
  cin >> m;
  
  for (int i = 1; i <= m; i++) {
      string ss;
      cin >> ss;
    int ans = find_(ss);
    cout << ans << endl;
  }

  return 0;
}
