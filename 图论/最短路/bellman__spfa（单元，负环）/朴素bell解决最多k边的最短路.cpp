#include <algorithm>
#include <cstring>
#include <iostream>
//AcWing 853. 有边数限制的最短路
using namespace std;

const int N = 510, M = 10010;

struct Edge {// 只要存每条边就行   不需要临边关系
  int a, b, c;
} edges[M];

int n, m, k;
int dist[N];
int last[N];

void bellman_ford() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;// 起始
  for (int i = 0; i < k; i++) {//循环k次保证边数限制
    memcpy(last, dist, sizeof dist);//备份防止这次循环 松弛串联的边 影响边数限制
    for (int j = 0; j < m; j++) {//  所有边
      auto e = edges[j];
      dist[e.b] = min(dist[e.b], last[e.a] + e.c);
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    edges[i] = {a, b, c};
  }

  bellman_ford();

  if (dist[n] > 0x3f3f3f3f / 2)//可能会被负数更新 所以不能写==inf
    puts("impossible");
  else
    printf("%d\n", dist[n]);

  return 0;
}
