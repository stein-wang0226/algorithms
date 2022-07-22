#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstring>
#define LOCAL
using namespace std;
//棋盘游戏  :最大匹配+思维
//避免放在同一行同一列，利用二分图最大匹配，二分图的两个集合分别代表***行和列***，最大匹配数即为最多可以放的棋子
//**(每一条匹配的边，代表霸占了一行一列的一个点)
//所求重要点即去掉后影响最大匹配
struct node{//存点
int x,y;
}Node[10005];
int k, m, n, G[505][505], link[505];  // G[u][v]   link存右点对象
int vis[505];     //对每次匹配右点访问过与否，防止重复
int dfs(int u) {  //*****从左侧搜
  for (int v = 1; v <= n; v++) {  //对每个右侧点遍历
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
int main()
{

#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
int Case=0;
while(cin>>m>>n>>k){
  
  Case++;//情况数
  int u,v;
  memset(G,0,sizeof G);
  memset(Node,0,sizeof Node);
  for(int i=1;i<=k;i++){
    cin>>u>>v;
    Node[i].x=u;
    Node[i].y=v;
    G[u][v]=1;
  }
  int ans=hungary();
  int sum=0;//记录重要点数
  for(int i=1;i<=k;i++){//枚举少某个点的情况
      int ret;
      G[Node[i].x][Node[i].y]=0;
      ret=hungary();
      if (ans>ret)sum++; 
      G[Node[i].x][Node[i].y] = 1;  //复原
  }


printf("Board %d have %d important blanks for %d chessmen.\n",Case,sum,ans);
//chessmen 即为原先最大匹配

}
 
    return 0;
}
