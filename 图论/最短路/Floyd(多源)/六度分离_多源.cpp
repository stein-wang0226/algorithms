#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int inf=0x3f3f3f3f;
//任意两人之间最短路小于等与7***等于也成立
//多源最短路--floyd
int n,m,dis[105][105];
void floyd(){//插点法
    for(int k=0;k<n;k++){//插点在外层     用 n 个点更新每一条边 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);//松弛
            }
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n>>m){
    memset(dis,0x3f,sizeof dis);
    for(int i=0;i<n;i++){//到自己距离为0 与dij不同
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int a,b,dist;
        cin>>a>>b;
        dis[a][b]=dis[b][a]=1;
    }
    floyd();
    int flag=1;
    for(int i=0;i<n;i++){
        if(!flag)break;
        for(int j=0;j<n;j++){
                if(dis[i][j]>7){
                    flag=0;
                    break;
                }
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
    return 0;
}
