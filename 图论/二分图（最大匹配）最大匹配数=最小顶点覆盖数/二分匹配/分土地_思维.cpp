#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;
//有N * N 的土地，其中某些点被挖成池塘了，其余的地方为空地，
//现在要分成 1 * 2 的空地来出售，
//思维：和四个方向匹配 ，奇偶分离：只处理奇数（奇数点和偶数点匹配）或结果/2
const int d[4][2]={1,0,0,1,-1,0,0,-1};
int n,m,k,link[100005],vis[100005];//不需定义g[u][v]判断是否能相连而是在dfs中判断****
bool mp[105][105];
bool dfs(int u)
{
    for(int i=0;i<4;i++)//四个方向
    {
        int x=u/m+d[i][0],y=u%m+d[i][1];//***
        if(x<0||y<0||x>=n||y>=m)continue;
        int v=x*m+y;//
        if(!vis[v]&&!mp[x][y])
        {
            vis[v]=1;
            if(link[v]==-1||dfs(link[v]))
            {
                link[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary()
{
    int ans=0;
    memset(link,-1,sizeof(link));
    for(int i=0;i<n*m;i++)//二维变一维
    {
        int x=i/m,y=i%m;
        if((x+y)&1&&!mp[x][y])//对奇数位置dfs
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))ans++;
        }
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m),n|m)
    {
        scanf("%d",&k);
        memset(mp,0,sizeof(mp));
        while(k--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mp[--x][--y]=1;//从0开始
        }
        printf("%d\n",hungary());
        for(int i=0;i<n*m;i++)
                if(link[i]!=-1)
                    printf("(%d,%d)--(%d,%d)\n",link[i]/m+1,link[i]%m+1,i/m+1,i%m+1);
    }
    return 0;
}