#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//染色问题--dfs
int m,n,sx,sy,ans=0;
char Map[25][25],vis[25][25];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int check(int x,int y){
    if(x>0&&x<=m&&y>0&&y<=n)return 1;
    else return 0;
}
void dfs(int sx,int sy){
    for(int i=0;i<4;i++){
        int curx=sx+dx[i];
        int cury=sy+dy[i];
        if(check(curx,cury)){
            if(!vis[curx][cury]&&Map[curx][cury]=='.'){
                ans++;
                vis[curx][cury]=1;
                dfs(curx,cury);
            }
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
while(cin>>n>>m,m*n){//这里列行反
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        cin>>Map[i][j];
        if(Map[i][j]=='@'){
            sx=i;
            sy=j;
        }
    }
}
memset(vis,0,sizeof vis);
ans=1;
dfs(sx,sy);
cout<<ans<<endl;
}
    return 0;
}
