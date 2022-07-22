#include <bits/stdc++.h>
#define LOCAL
//#define int long long
using namespace std;
const int N=1e4+5;
// 记忆化搜索   要搜每个点 但可以直接使用之前答案
int T,n,m;
int Map[N][N];
int dx[4]={1,-1,0,0,};
int dy[4]={0,0,-1,1};
int vis[N][N];
int ans[N][N];// 答案  +标记
bool is_ok(int i,int j){
    if(i>=1&&i<=n&&j>=1&&j<=m)return 1;
    return 0;
}
int dfs(int i,int j){
    int ret=0;
    if(ans[i][j])return ans[i][j];   //搜过直接返回
    for(int k=0;k<4;k++){
        int curx=i+dx[k];
        int cury=j+dy[k];
        if(is_ok(curx,cury)&&Map[curx][cury]<Map[i][j])
        ret=max(dfs(curx,cury),ret);//   找到最长路
    }
    ans[i][j]=ret+1; // 存答案
    return ans[i][j];
}
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        cin>>Map[i][j];
    }
}
int maxx=0;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        maxx=max(maxx,dfs(i,j));
    }
}
cout<<maxx<<endl;
    return 0;
}
