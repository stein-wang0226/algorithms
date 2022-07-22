#include <bits/stdc++.h>
#define LOCAL
//#define int long long
// 判断是否有环--找不到入度为0的点
using namespace std;
const int N=3e5+5;
const int M=1e6+5;
struct Edge{
    int from,to,next;
}edge[M];
int head[N];
vector<int>ans;
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
while(cin>>n>>m,m+n){    
    tot=0;
    memset(head,-1,sizeof head);
    memset(in,0,sizeof in);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        in[v]++;
    }
    queue<int>que;
    int cnt=0;
    for(int i=0;i<n;i++){//0kaishi
        if(in[i]==0){
            que.push(i);//
            cnt++;
        }
    }
    
    while(!que.empty()){
        int u=que.front();que.pop();
        ans.push_back(u);
        for(int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            in[v]--;
            if(in[v]==0){que.push(v);cnt++;}
        }
    }
    if(n==cnt)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
    return 0;
}
