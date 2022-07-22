#include<bits/stdc++.h>
using namespace std;
//方格取数  看作两条路径 同时走
//dp[i1][j1][i2][j2]  表示分别走到 （i1,j1） (i2,j2) 的最大值之和
//发现  i1+j1==i2+j2  所以3维即可
//  设k=i+j  则 dp[k][i1][i2] 
const int N = 15;
int n;
int w[N][N];
int f[N * 2][N][N];
int main()
{
    scanf("%d", &n);
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c) w[a][b] = c;

    for (int k = 2; k <= n + n; k ++ )
        for (int i1 = 1; i1 <= n; i1 ++ )
            for (int i2 = 1; i2 <= n; i2 ++ )
            {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
                {
                    int t = w[i1][j1];
                    if (i1 != i2) t += w[i2][j2];  //终点不同
                    int &x = f[k][i1][i2];  
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);//动向右
                    x = max(x, f[k - 1][i1 - 1][i2] + t);  //i1 向右  i向下
                    x = max(x, f[k - 1][i1][i2 - 1] + t);  //
                    x = max(x, f[k - 1][i1][i2] + t);  //都向下
                }
            }
    printf("%d\n", f[n + n][n][n]);
    return 0;
}
