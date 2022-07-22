//还是行列建模法，求得行列最大匹配即为最多炮台数，任意不为X的点皆可生成边
//处理墙(难点)：所以要把有墙间隔的行作为两行或多行(被分开就是一行)。列同理，然后给所有的行，列重新编号，最后再用套路法建模，跑一遍二分图。  //坐标为x,y对应第几“行”  “列”
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
char map[10][10];
int hang[10][10];
int lie[10][10];
int G[110][110];
int pipei[10];
bool used[10];
int N, M;
void init()
{
    memset(G,0,sizeof(G));
 
}
void getMap()
{
    for(int i = 0; i < N; i++)
    {
        scanf("%s",map[i]);
    }
}
int dfs(int x,int n)
{
    for(int i = 0; i < n; i++)
    {
        int y = G[x][i];
        if(y&&!used[i])
        {
            used[i] = true;
            if(pipei[i] == -1 || dfs(pipei[i],n))
            {
                pipei[i] = x;
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    int ans = 0;
    int an=0;
    for(int i=0;i<N;i++,an++)
    {
 
        for(int j=0;j<N;j++)
        {
            if(map[i][j]=='X'&&j+1<N&&map[i][j+1]!='X')an++;
            hang[i][j]=an;
        }
 
    }
    int ann=0;
    for(int j=0;j<N;j++,ann++)
    {
 
        for(int i=0;i<N;i++)
        {
            if(map[i][j]=='X'&&i+1<N&&map[i+1][j]!='X')ann++;
            lie[i][j]=ann;
        }
 
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j]!='X')G[hang[i][j]][lie[i][j]]=1;
        }
    }
    memset(pipei, -1, sizeof(pipei));
    for(int i = 0; i <an; i++)
    {
        memset(used, false, sizeof(used));
        ans += dfs(i,ann);
    }
    printf("%d\n", ans);
}
int main()
{
    while(scanf("%d", &N)&&N)
    {
        init();
        getMap();
        solve();
    }
    return 0;
}