#include <bits/stdc++.h>
//#define LOCAL
using namespace std;
//朴素的dijkstra   稠密图
const int inf = 0x3f3f3f3f;
int m, n, Map[505][505], dis[505], vis[505], S, T;
void init() {
	memset(Map, 0x3f, sizeof Map); //初始化正无穷
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
}
void dij(int S, int T) {
	dis[S] = 0; //
	vis[S] = 1;
	while (S != T) { //从小到大找最短路，直到找到T就无需继续
		int Min = inf;
		int next;
		for (int i = 1; i <= n; i++) { //**每次从当前起点找其的最短路
			if (Map[S][i] != inf&&!vis[i]) //存在道路
				dis[i] = min(dis[i], Map[S][i] + dis[S]); //**对每个相连点松弛操作
			if ( dis[i] < Min) { //更新当前最短路
				next = i;           //找下一个最近的 做起点
				Min = dis[i];
			}
		}
		if (Min == inf)  break; //之后都没有道路，跳出
		S = next; //更新起点以做下一个松弛操作
		vis[S] = 1; //标记已生成过
	}
}
int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	while (cin >> n >> m, m + n) {
		init();
		for (int i = 1; i <= m; i++) {
			int a, b, dist;
			cin >> a >> b >> dist;
			Map[a][b] = min(dist, Map[a][b]);
			//	Map[b][a] = Map[a][b]; //无向图
		}
		S = 1;
		T = n;
		dis[S] = 0; //
		vis[S] = 1;
		dij(S, T);
		if (dis[T] == inf)cout << "-1" << endl;
		else	cout << dis[T] << endl;

	}

	return 0;
}
