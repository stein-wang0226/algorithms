#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3)
//#define int long long
using namespace std;
//求树的直径
//固定根结点（1）： 求出穿过每个结点的路径最大值，之后遍历求最大值即可

//求法：对每个接结点向下走到叶节点的最长链和次长链相加
const int N = 2e5 + 5;

int T, n, a[N];
int head[N],tot;
struct Edge{
    int from,to,w,next;
}edge[N*2];
void add(int u,int v,int w){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot;
}


int ans=0;

int dfs(int u,int fa){
    int d1=0,d2=0;  //最长链和次长链
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        int w=edge[i].w;
        int d=dfs(v,u)+w;  //链长度
        if(d>d1){
            d2=d1;d1=d;   // 依次更新
        }
        else if(d>d2)d2=d;
    }
    ans=max(ans,d1+d2);
    return d1; //返回最长链
}
signed main() {
cin>>n;
int u,v,w;
memset(head,-1,sizeof head);
tot=0;
for(int i=1;i<=n-1;i++){
    cin>>u>>v>>w;
    add(u,v,w);
    add(v,u,w);
}

dfs(1,0);

cout<<ans<<endl;
  return 0;
}
