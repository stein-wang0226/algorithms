#include <stdio.h>
int main()
{
    int dis[10], i, k, n, m;
    int inf = 999999999;
    
    n = m = 5;  // 顶点  边的个数
    
    int u[10] = { 0, 2,1,1,4,3 };  // 起点
    int v[10] = { 0, 3,2,5,5,4 };  // 终点
    int w[10] = { 0, 2,-3,5,2,3 };  // 权值

    for (i = 1; i <= n; i++)	// 初始化为估计值
        dis[i] = inf;
    dis[1] = 0;

    // 对每一条边进行  n - 1 次松弛
    for (k = 1; k <= n - 1; k++) {
        for (i = 1; i <= m; i++) {//更新 每条边终点的最短路 
    	    if (dis[v[i]] > dis[u[i]] + w[i])
    		dis[v[i]] = dis[u[i]] + w[i];
  	}
    }
    
    for (i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }

    return 0;
}
