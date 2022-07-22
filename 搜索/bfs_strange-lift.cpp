#include<bits/stdc++.h>
using namespace std;
int n, a, b, k[205], vis[205] = {0}, step[205];
int main(){
        while (scanf("%d%d%d", &n,&a,&b) , n) {
          for (int i = 1; i <= n; i++) {  // input
            scanf("%d", &k[i]);
          }
          memset(vis, 0, sizeof(vis));
          memset(step, 0, sizeof(step));

          queue<int>que;
          que.push(a);
          int flag = 0;
          step[a] = 0;
          while (!que.empty()) {
            int u = que.front();
            if (u == b) {
              flag = 1;
              break;
            }
            que.pop();                                                //出队
            if (u + k[u] > 0 && u + k[u] <= n && (!vis[u + k[u]])) {  // up
              que.push(u + k[u]);
              vis[u + k[u]] = 1;
              step[u + k[u]] = step[u] + 1;
            }
            if (u - k[u] > 0 && u - k[u] <= n && (!vis[u - k[u]])) {  // down
              que.push(u - k[u]);
              vis[u - k[u]] = 1;
              step[u - k[u]] = step[u] + 1;
            }
          }
          if (flag)
            cout << step[que.front()] << endl;
          else
            cout << "-1"  << "\n";
               
        }

        return 0;
}
