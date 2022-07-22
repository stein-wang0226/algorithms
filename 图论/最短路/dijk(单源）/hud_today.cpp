#include<iostream>
#include<string>
#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;
int G[155][155], vis[155], dis[155];
map<string, int> cnt;
int t, n;

int dijkstra(int S,int E) {
    int u;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= t; i++) dis[i] = G[S][i];
    dis[S] = 0;
    vis[S] = 1;
    for(int i = 1; i < n; i++) {
        int minn = inf;
        for(int j = 0; j <= t; j++) {
            if(!vis[j] && dis[j] < minn) {
                minn = dis[u = j];
//                u = j;
            }
        }
        if(minn == inf) continue;
        vis[u] = 1;
        for(int j = 1; j <= t; j++) {
            if(!vis[j] && dis[j] > dis[u] + G[u][j])
            dis[j] = dis[u] + G[u][j];
        }
    }
    return dis[E];
}

int main() {
    int S, E, x;
    string s1, s2;
    while(scanf("%d", &n) && n != -1) {
        t = 0;
        cnt.clear();
        memset(G, inf, sizeof(G));
        cin >> s1 >> s2;
        cnt[s1] = ++t;
        S = t;
        if(!cnt.count(s2))
        cnt[s2] = ++t;
        E = t;
        for(int i = 1; i <= n; i++) {
            cin >> s1 >> s2 >> x;
            if(!cnt.count(s1)) cnt[s1] = ++t;
            if(!cnt.count(s2)) cnt[s2] = ++t;
            G[cnt[s2]][cnt[s1]] = G[cnt[s1]][cnt[s2]] = min(x, G[cnt[s1]][cnt[s2]]);//取小值 
        }
        int ans = dijkstra(S, E);
        if(ans == inf) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
