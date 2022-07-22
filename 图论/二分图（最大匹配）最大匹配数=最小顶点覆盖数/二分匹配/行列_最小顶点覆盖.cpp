//题目大意：扎气球，每选择一种颜色的气球扎，每次只能选择把某一行或者某一列的该颜色的所有气球扎破，问有哪几种颜色的气球不能在k times 内全部扎破？
//对于颜色k的每一个气球来说，如果位于(x,y)的气球被扎破，那么x行或者y列肯定被选择过，我们要找的就是是否在限定次数内，
//每一个该颜色的气球所在的x行和y列都被选择过。对于该颜色位于(x,y)的气球，我们连一条x到y的边，如果该边的任意一端被选择过，那么这个气球就被扎破了，
//所以我们要求的就是使所有边至少一端被选择了，也就是最小点覆盖是否比给定的times大就行了。
//和
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int n,k,G[105][105],Map[105][105],vis[105],link[105];
int dfs(int u){
    for(int v=1;v<=n;v++){
        if(G[u][v]==1&&!vis[v]){
            vis[v]=1;
            if(link[v]==-1||dfs(link[v])){
                link[v]=u;
                return 1;
            }
        }
    }
return 0;
}

int hungary(){
    int ret=0;
memset(link,-1,sizeof link);
for(int u=1;u<=n;u++){
memset(vis,0,sizeof vis);
if(dfs(u))ret++;
}

return ret;
}

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n>>k,n+k){
memset(Map,0,sizeof Map);
set<int>St;
int cnt=0;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cin>>Map[i][j];
        if(!St.count(Map[i][j]))St.insert(Map[i][j]),cnt++;
    }
}
int flag=0;
int flag1=0;
for(auto t:St){
    memset(G,0,sizeof G);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                if(Map[i][j]==t){
                    G[i][j]=1;//行——>列相连
                }
        }
    }

  if(hungary()>k){
      flag=1;
     
    if(!flag1)cout<<t;//结尾无空行 :)
    else cout<<" "<<t;
     flag1=1;
  }


}
if(!flag)cout<<"-1"<<endl;
else cout<<endl;

}
    return 0;
}
