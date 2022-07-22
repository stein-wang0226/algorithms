#include <bits/stdc++.h>
#define LOCAL
using namespace std;//可以反复走
int t,Map[10][10],vis[10][10],m,n;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct node{
int x,y,left,time;
};
node start;
int bfs(){
  queue<node>q;
  q.push(start);
  while(!q.empty()){
    node u=q.front();
    q.pop();
    if(u.left<=0)continue;//判断跳出
    if(Map[u.x][u.y]==3){
      return u.time;
    }
    node cur;
    for(int i=0;i<4;i++){
        cur.x=u.x+dx[i];
        cur.y=u.y+dy[i];
        cur.left=u.left-1;
        cur.time=u.time+1;
        if(Map[cur.x][cur.y]==4&&cur.left>0){cur.left=6;}//reset,标记不然会超时**
        if(!vis[cur.x][cur.y]&&cur.x>0&&cur.x<=m&&cur.y>0&&cur.y<=n&&Map[cur.x][cur.y]!=0)
       {if(Map[cur.x][cur.y]==4)vis[cur.x][cur.y]=1;//需写在判断压入队列之后
          q.push(cur);}
    }
  }
return -1;
}
int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>t;
while(t--){
cin>>m>>n;
memset(vis,0,sizeof vis);
memset(Map,-1,sizeof Map);
for(int i=1;i<=m;i++){
  for(int j=1;j<=n;j++)
  {  
    cin>>Map[i][j];
    if(Map[i][j]==2){
      start.x=i;
      start.y=j;
      start.left=6;
      start.time=0;
    }
}
}
int ans=bfs();
cout<<ans<<endl;;

}
    return 0;
}
