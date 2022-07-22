#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;
//树的重心
//重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中（子树）点数的最大值最小，那么这个节点被称为树的重心。
// 固定根一次dfs 回溯 每次比较每个结点的所有子树大小和除包含该节点子树外的所有点数 取最大  依次比较取最小即可
const int N = 2e5 + 5;

int T, n, a[N];
int head[N],tot;

int ans=0x3f3f3f3f;

struct Edge{
    int from,to,next;
}edge[2*N];
void add(int u,int v){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}

int dfs(int u,int fa){
    int size=1,s=0,maxx=0;// 这棵树大小  每颗子树大小和最大子树大小
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        s=dfs(v,u);
        maxx=max(maxx,s); //最大子树
        size+=s;
    }
    maxx=max(maxx,n-size);  //向上根对应的“子树”
    ans=min(ans,maxx);  //重心
    return size;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

    cin>>n;memset(head,-1,sizeof head);
    tot=0;
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }

    dfs(1,0);
    cout<<ans<<endl;
  return 0;
}
