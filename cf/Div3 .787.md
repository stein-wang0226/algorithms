# Div3 .787

## E: 并查集思想  贪心思维

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
// e   并查集  从大往小考虑
//发现如果找到最大的能变a的字符mx（<=a+'k'的最大字符）  那么字符串中所有小于mx都能变a  
//  由于要字典序最小  所以从前往后  枚举字符  s[i] 若s[i]>k 那么 s[i]不能变a   
const int N = 2e5 + 5;
int T, n,k, a[N];
void solve(){
    string s;
    cin>>n>>k>>s;
    int  mx=0;
    for(int i=0;i<n;i++){//从前向后枚举  前面优先
        if(s[i]-'a'>k){ //不能变a
            char L=s[i]-(k-mx);  //最多变到L 剩下用完
            char R=s[i];
            for(int j=0;j<n;j++){
                if(L<=s[j]&&s[j]<=R)s[j]=L; //先变L
            }
            break; //用完了跳出
        }
    mx=max(mx,(int)(s[i]-'a'));  //对之前都能变a 则找最大的那个字符
    }

    for(int i=0;i<n;i++){
        if(s[i]<='a'+mx)s[i]='a';
    }
cout<<s<<endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}

```

## F:dfs dp

### 题意：

给一颗n（<=2e5）个结点的树，有k个目标点，从x出发，经k个点，最后到达y最小路程。

### 思路：

问题转化为  从根节点出发经过一些点后回到根节点的最短路

即再x->y路径上的点为根节点的不包含路径中点的子树所需要路径总和

两次dfs  第一次记录：son[u]记录u子树中目标点个数 path[u]记录u是否在x->y 路径上



第二次  计算路径和 对于不在x->y上的点  u  若其子节点v子树中有目标点 ：son[v]>0

那么v的贡献为 1+dfs(v)+1  ***(走到v 拿目标再返回父节点)  递归即可

再加上x-->y路径上长度

```C++
#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n,m, a[N];
int x,y;
int son[N],path[N];//子树中目标点个数    u是否在x->y 路径上
int head[N],tot;
struct Edge{
    int to,next;
}edge[N*2];
void add(int u,int v){
    edge[++tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}

void dfs1(int u,int fa){
    for(int i=head[u];~i;i=edge[i].next){
       	int v=edge[i].to;
        if(v==fa)continue;
        dfs1(v,u);
        son[u]+=son[v];//
        path[u]|=path[v];//
    }
}

int dfs2(int u,int fa){
    int res=0;
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        if(!path[v]&&son[v])res+=dfs2(v,u)+2;
    }
    return res;
}
void solve(){
    cin>>n>>m;
	memset(son,0,sizeof son);
    memset(path,0,sizeof path);
    tot=0;
    memset(head,-1,sizeof head);
    cin>>x>>y;
    int u,v;
    for(int i=1;i<=m;i++){//目标点
        cin>>u;
        son[u]=1;
    }
    path[y]=1;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    
    dfs1(x,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(path[i])ans+=dfs2(i,0); //只用搜再路径上的点
    }
    ans+=count(path+1,path+1+n,1)-1; //加上x-->y路径长度
    cout<<ans<<endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
      solve();
  }
  return 0;
}

```

