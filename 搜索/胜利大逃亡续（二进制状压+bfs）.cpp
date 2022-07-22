#include <bits/stdc++.h>
#define LOCAL
using namespace std;
//二进制状压 +bfs
//锁和钥匙最多有10把，我们可以用10个二进制数来表示当前的拥有的钥匙状态,
//1111111111 每一位0或者1来表示是否有这个钥匙。
//如果当前状态下又得到钥匙我们可以用 | 运算符处理得到新状态
//如果当前遇到锁，我们可以用 & 运算符来判断是否有这个钥匙
char Map[50][50];
int vis[50][50][1 << 10];  //**同时标记位置和状态
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct node {
  int x, y, state;  //定义状态
  int step;

} S, T;
int m, n, t;

void bfs() {
  queue<node> q;
  q.push(S);
  while (!q.empty()) {
  node u=q.front();
  q.pop();
	if(Map[u.x][u.y]=='^'&&u.step<=t-1){//成功逃出
		cout<<u.step<<endl;
		return;
	}
	node cur;
	for(int i=0;i<4;i++){
	cur.x=u.x+dx[i];
	cur.y=u.y+dy[i];
	if(Map[cur.x][cur.y]=='*')continue;//墙
	 if(cur.x<=0||cur.y<=0||cur.x>m||cur.y>n) continue;
	//避免出错分类计算
	//1
	if(Map[cur.x][cur.y]>='A'&&Map[cur.x][cur.y]<='J'){//遇到门
		if(u.state&(1<<(Map[cur.x][cur.y]-'A'))){//按位与判断是否有钥匙
			cur.state=u.state;
			cur.step=u.step+1;
			if(!vis[cur.x][cur.y][cur.state]){//状态未出现
			vis[cur.x][cur.y][cur.state]=1;
			q.push(cur);//压入
			}
		}
		else continue;//否则走不通

	}
	//2
	if(Map[cur.x][cur.y]>='a'&&Map[cur.x][cur.y]<='j'){//捡到钥匙
	cur.step=u.step+1;
	cur.state=(u.state|(1<<(Map[cur.x][cur.y]-'a')));//捡钥匙，按位或
    if(!vis[cur.x][cur.y][cur.state]){//同上
	vis[cur.x][cur.y][cur.state]=1;
	q.push(cur);//压入
	}
  }

else{//为'.'
	cur.state=u.state;
	cur.step=u.step+1;
	if(!vis[cur.x][cur.y][cur.state]){
		vis[cur.x][cur.y][cur.state]=1;
		q.push(cur);
	}

	
}
  
  
  }
}
cout<<"-1"<<endl;
}
int main() {
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  while (cin >> m >> n >> t) {
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> Map[i][j];
        if (Map[i][j] =='@') S = {i, j, 0, 0};  //起点
        if (Map[i][j] == '^') T = {i, j, 0, 0};  //出口
      }
    }
    memset(vis, 0, sizeof vis);
    bfs();
  }

  return 0;
}
