#include <bits/stdc++.h>
#define LOCAL
//#define int long long
// 反向拓扑排序 优先队列大顶堆  倒序输出即可
// 因为 限制条件导致大编号可能在小的前  而在没有限制是总优先考虑小的eg.   4 2    5 1 .
//所以反向拓扑 编号大的在前 反向输出 
using namespace std;
const int N=3e5+5;
const int M=10e5+5;
struct Edge{
    int from,to,next;
}edge[M];
int head[N];
int T,n,m,tot,in[N];
void add(int u,int v){
    edge[++tot].from=u;
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}
signed main(){
    std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>T;
while(T--){
    cin>>n>>m;
    tot=0;
    memset(head,-1,sizeof head);
    memset(in,0,sizeof in);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(v,u);    //fan
        in[u]++;
    }
    priority_queue<int>que;//大顶堆；
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            que.push(i);//
        }
    }
    vector<int>ans;
    while(!que.empty()){
        int u=que.top();que.pop();
        ans.push_back(u);
        for(int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            in[v]--;
            if(in[v]==0)que.push(v);
        }
    }
for(int i=ans.size()-1;i>=0;i--){
if(i==0)cout<<ans[i];
else cout<<ans[i]<<" ";
}
cout<<endl;
}
    return 0;
}
