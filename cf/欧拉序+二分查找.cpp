#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
using namespace std;
//The maximum gcd of a path equals the maximum weight of an edge in the tree
//等价于找到 相连ab满足其边权最大

//出两个点a , b a, ba,b, 满足连接这两个点的边权是最大的.

//同理, 每次询问时, 系统返回的答案我们可以看作是当前点集中的最大边权
//考虑欧拉序 将树 --》线性    二分查找区间即可
const int N = 2e3 + 5;
int T, n, a[N];
int head[N],tot;
int dfn[N*2]; //dfs序
int idx;
struct Edge{
    int from,to,next;
}edge[N*2];
void add(int u,int v){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}

void dfs(int u,int fa){//求dfs序  
    dfn[++idx]=u;
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        dfn[++idx]=u;
    }
}


int ask(int l,int r){ //询问
    set<int >st;
    for(int i=l;i<=r;i++)st.insert(dfn[i]);
    	cout << "? " << st.size() << ' ';
		for (auto& op : st) cout << op << ' ';
		cout << endl;
        int x;cin>>x;
        return x; //
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

cin>>n;
int u,v;
memset(head,-1,sizeof head);
tot=0;
idx=0;
for(int i=1;i<n;i++){
    cin>>u>>v;
    add(u,v);
    add(v,u);
}
dfs(1,0);
    int l=1,r=idx;
    int res=ask(1,idx); //最终结果
    while(l+1<r){ // 
        int mid=l+r>>1;
        if(ask(l,mid)==res){//答案在这个区间
            r=mid;
        }
        else l=mid;
    }
    cout<<"! "<<dfn[l]<<' '<<dfn[r]<<endl;
  return 0;
}
