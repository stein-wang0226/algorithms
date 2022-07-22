#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#define LOCAL
using namespace std;
//伞兵air raid --gad最小路径覆盖=（n-m）   理解：路径数+匹配数=n  =》最小路径+最大匹配=n
//拆分二分图（入点 出点）
int t, m, n, G[505][505], link[505];  // G[u][v]   link存右点对象
int vis[505];     //对每次匹配右点访问过与否，防止重复
int dfs(int u) {  //*****从左侧搜
  for (int v = 1; v <= m; v++) {  //对每个右侧点遍历
    if (G[u][v] && !vis[v]) {     //已访问过则无需继续
      vis[v] = 1;
      if (link[v] == -1 ||
          dfs(link[v])) {  //****
                           //若v未匹配则匹配上,返回true,或继续向后搜直到匹配上
        link[v] = u;  // u ,v相匹配,为之后服务
        return 1;     //匹配上返回true
      }
    }
  }
  return 0;//匹配不上返回false
}
int hungary() {
  int res = 0;                    //最大匹配数
  memset(link, -1, sizeof link);  //初始化link为-1,都未匹配,无对象
  for (int u = 1; u <= m; u++) {  //遍历左侧点向右匹配
    memset(vis, 0, sizeof vis);   //每次 匹配初始化vis 0
    if (dfs(u)) res++;            // dfs搜索,如果搜到匹配数+1;
  }
  return res;
}

int main() {
  int index,u, v; //左 右
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
cin>>t;
  while (t--){
    cin >> m >> n;//节点数  边数
    memset(G,0,sizeof G);
    for (int i = 1; i <= n; i++) {
      cin>> u >> v;
      G[u][v] = 1;  
    }
    int ans = hungary();
    cout<<m-ans<<endl;
  }
  return 0;
}
