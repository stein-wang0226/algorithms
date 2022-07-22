#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int mod=998244353;
//题目等同于 给定n个点和n-1 个点对点权比值
// 等同 n 个点的树 每条边表示相连两点比值为w
// 求最小点权和  
//发现只要求出根结点权值即可根据比例求出所有点
//我们从点 1 开始dfs，对于其相邻的点 v ，如果 a[v] 为整数，我们需要保证 val 为 y 的倍数。  y/x
// 求出所有分母的所有因子的最大个数    减去分子所含的质因子个数  （分子相当于提供因子，接下来分母可以直接使用）
// 回溯时要还原
int T, n, a[N],tot,head[N],ans;  //a每个结点权值
vector<pair<int,int>>fac[N];  //fact[i]为i 的所有因子及其次数
int cnt[N];//每个质因子总出现次数
int maxx[N];  //每个质因子最大出现次数
struct Edge{
  int from,to,x,y,next;
}edge[N*2];
void add(int u,int v,int x,int y){
  edge[++tot].from=u;
  edge[tot].to=v;
  edge[tot].x=x;
  edge[tot].y=y;
  edge[tot].next=head[u];
  head[u]=tot;
}

int qpow(int a,int k){
  int res=1;
    while(a){
      if(k&1)res=res*a%mod;
      k>>=1;
      a=a*a%mod;
    }
    return res;
}
void dfs1(int u,int fa){

  for(int i=head[u];~i;i=edge[i].next){
    int v=edge[i].to;int x=edge[i].x;int y=edge[i].y;
    if(v==fa)continue;
    for(auto p:fac[x]){
      cnt[p.first]+=p.second;   // 加上当前分子的所有因子
      maxx[p.first]=max(maxx[p.first],cnt[p.first]);//取最大值  
    }
    for(auto p:fac[y]){// 减去分母所含因子
      cnt[p.first]-=p.second;
    }
    dfs1(v,u);
    for(auto p:fac[y])cnt[p.first]+=p.second;//回溯复原
    for(auto p:fac[x])cnt[p.first]-=p.second;
  }
}

void dfs2(int u,int fa){
    ans+=a[u];
    for(int i=head[u];~i;i=edge[i].next){
      int v=edge[i].to;int x=edge[i].x;
      int y=edge[i].y;
      if(v==fa)continue;
      a[v]=(a[u]*y)%mod*qpow(x,mod-2)%mod;
      dfs2(v,u);
    }
}

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  //预处理质因子 试除法
  for(int i=2;i<=200000;i++){// i 的所有质因子及其出现次数
    int t=i;
    for(int j=2;j<=i/j;j++){
      int cnt=0;
      while(t%j==0)t/=j;cnt++;
      if(cnt)fac[i].push_back({j,cnt});
    }
    if(t!=1)fac[i].push_back({t,1});
  }
  cin >> T;
  while (T--) {
    tot=0;
    memset(head,-1,sizeof head);
    memset(maxx,0,sizeof maxx);
    cin>>n;
    int u,v,x,y;
    int gcd=__gcd(x,y);
    x/=gcd;y/=gcd;    // 约分   
    for(int i=1;i<=n;i++){
        cin>>u>>v>>x>>y;
        add(u,v,x,y);
        add(v,u,y,x);
    }

  dfs1(1,0);
  int val=1;
  for(int i=1;i<=n;i++)
    if(maxx[i]){// 存在因子
      val*=qpow(i,maxx[i])%mod;
    }
    a[1]=val;
  ans=0;
  dfs2(1,0);
  cout<<ans<<endl;
  }

  return 0;
}
