#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define int long long
#define endl "\n"
using namespace std;
//拓扑排序
//输入层 输出层 --入度  出度为0 
// 因为后一个点被前一个点更新 所以按拓扑序递推即可

const int N = 2e3 + 5;
int T, n, m,a[N];
int c[N],u[N];
int in[N],out[N];
int head[N],tot;
struct Edge{
    int from,to,w,next;
}edge[N*2];
//vector<int>ans;
void add(int u,int v,int w){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot;
}
void solve(){
    cin>>n>>m;
    memset(head,-1,sizeof head);
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
    tot=0;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>u[i];
        if(c[i]==0){
                c[i]=-u[i]; //非输出层  直接初始化-u
        }
    }

    for(int i=1;i<=m;i++){
            int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
      //  add(v,u,w);
        out[u]++;
        in[v]++;
    }
        vector<int> ans_id;//输出层
    for(int i=1;i<=n;i++){
        if(out[i]==0)ans_id.push_back(i);
    }

//tpposort
queue<int>que;
for(int i=1;i<=n;i++){
    if(in[i]==0)que.push(i);
}
while(!que.empty()){
    int u=que.front();que.pop();
    //ans.push_back(u);
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(c[u]>0)c[v]+=c[u]*edge[i].w;  // 计算
        if(--in[v]==0)que.push(v);
    }
}
int flag=0;
    for(auto i:ans_id){
        if(c[i]>0)cout<<i<<" "<<c[i]<<endl,flag=1;
    }
if(!flag) cout<<"NULL"<<endl;

}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


      solve();
  
  return 0;
}
