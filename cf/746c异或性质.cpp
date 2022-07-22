#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
//在至少一次，最多k-1次操作以内，是否能将当前树分为几个连通块，将这几个连通块内所有点的值进行异或，使得每个连通块的异或和相同。
//思路：
//根据异或的性质，如果xo为0，那么说明可以分成两个区间，其两个区间的异或之和一定为0。
//如果xo不为0，我们要分成m>=2个区间，每个区间为xo，如果我们能分成10个区间，那么一定能分成8个区间，因为我们可以选择相邻的三个连通分量构成一个大连通分量，其异或值还是为xo，因此，我们最后分成的奇数个连通分量的最小值是3。
//现在题目转化成，能不能分成3个连通分量，异或值相同。
//思路很简单，dfs遍历每个点的所有子树，如果其自身和子树的异或之和为xo，那么就断链并且记录个数cnt++，断链的方式就是给父节点返回0。
//如果最后cnt>=3 && k>=3 那么表示满足题意。

int T, n, a[N], k;
int head[N], tot;
int cnt;
struct Edge {
  int from, to, next;
} edge[N * 2];
void add(int u, int v) {
  edge[++tot].from = u;
  edge[tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot;
}

int sum; //全部异或和
int dfs(int u,int fa){
    int res=a[u]; //存子树异或和
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        res^=dfs(v,u);
    }
    if(res==sum){
        cnt++;    //该子树满足 断链
        return 0 ; //返回0  断链
    }
    return res;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
    cin >> n >> k;
    memset(head,-1,sizeof head);
    tot=0;
      sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum ^= a[i];
    int u, v;
    for (int i = 1; i < n; i++) {
      cin >> u >> v;
      add(u, v);
      add(v, u);
    }

    if (sum == 0) {
      cout << "YES" << endl;
      continue;
    }
    cnt=0;
   dfs(1,1);
    if(cnt>=3&&k>=3)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }
  return 0;
}
