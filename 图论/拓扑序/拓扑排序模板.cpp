#include <bits/stdc++.h>
//#define LOCAL
//define int long long
//拓扑排序模板
// 优先队列保证按同样地位从大到小输出
using namespace std;
int m,n,in[505];
vector<int>vec[505];
int vis[505][505];
int ans[505];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n>>m){
    int cnt=0;
    memset(in,0,sizeof in);
    memset(vis,0,sizeof vis);
    for(int i=0;i<=n;i++)vec[i].clear();
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(!vis[u][v]){//标记重边
        vec[u].push_back(v);
        in[v]++;
        vis[u][v]=1;
        }
    }
    priority_queue<int,vector<int>,greater<int>>que;// 小顶堆   字典序（原先默认大顶堆）
    // 直接queue也可
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int x=que.top();que.pop();
        ans[++cnt]=x;
        for(int i=0;i<vec[x].size();i++){
            int v=vec[x][i];
            in[v]--;
            if(in[v]==0)que.push(v);
        }
    }

    for(int i=1;i<=cnt;i++){
        if(i<cnt)cout<<ans[i]<<" ";
        else cout<<ans[i]<<endl;
    }

}
    return 0;
}
