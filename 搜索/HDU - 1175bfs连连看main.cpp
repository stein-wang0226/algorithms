#include <bits/stdc++.h>
#define LOCAL
using namespace std;  //
int t, Map[1005][1005], vis[1005][1005][4], m, n,k;//vis三维 标记某个点朝某方向走  不同方向可重复****(可从不同方向穿过同一个点)
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct node {
  int x, y, dir, num;  // cnt为转向次数,dir为当前方向
   bool operator <(const node &a)const//以转向次数为关键排序 优化
    {
        return num>a.num;
    }
}start,End;
int flag=0;
void bfs(node start,node End) {
priority_queue<node>q;//优化
  q.push(start);
  while (!q.empty()) {
    node u = q.top();
    q.pop();
    if (u.x==End.x&&u.y==End.y&&u.num<=2) {//满足**
      cout<<"YES"<<endl;
      flag=1;
      return ;
    }
    if(u.num>2)continue;
    node cur;
    for (int i = 0; i < 4; i++) {
      cur.x = u.x + dx[i];
      cur.y = u.y + dy[i];
      if(u.dir!=i){//用i代表方向****
        cur.dir=i;//方向变化
        cur.num=u.num+1;
      }
      else{//***方向不变
      cur.dir=u.dir;//  =i
      cur.num=u.num;
      }
      if (!vis[cur.x][cur.y][i] && cur.x > 0 && cur.x <= m && cur.y > 0 &&
          cur.y <= n && (Map[cur.x][cur.y] == 0||cur.x==End.x&&cur.y==End.y)) {//经过0或到终点
          vis[cur.x][cur.y][i] = 1; 
          q.push(cur);
      }
    }
  }
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> m >> n, m * n) {
    memset(vis, 0, sizeof vis);
       memset(Map, 0, sizeof Map);
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> Map[i][j];
      }
    }

    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>start.x>>start.y>>End.x>>End.y;
            memset(vis, 0, sizeof vis);
        if(Map[start.x][start.y]!=Map[End.x][End.y]||Map[start.x][start.y]==0||Map[End.x][End.y]==0){
          cout<<"NO"<<endl;
         continue;
        }
        flag=0;
        start.dir=-1;
        start.num=-1;//抵消第一次方向
        bfs(start,End);
        if(!flag)cout<<"NO"<<endl;
    }

  }
  return 0;
}
