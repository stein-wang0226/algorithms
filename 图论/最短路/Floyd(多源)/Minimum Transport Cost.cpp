#include<stdio.h>
#include<string.h>
 //题意：
//有N个城市，给出一个N*N邻接矩阵，-1表示此路不通
//给出一行N个数表示借助该点，所需额外权值。
//接下来给出起点终点，求任意两点，最短路路径 及其 最小权值。
//最短路路径输出，顺便找到字典序最小，额外开一个path[u][v] 数组，记录u到v的第一个一个需要行走的点，然后循环查找。
#define For(a,b,c) for(int a = b; a <= c; a++)
#define mem(a,b) memset(a,b,sizeof(a))
int N, M, ans;
int e[105][105], fee[105];
int path[105][105];
void bfs(int u, int v)
{
    printf("Path: %d",u);
    if(u == v) {printf("\n"); return;} //u == v 只输出一点
    int now = path[u][v];
    while(1)
    {
        printf("-->%d",now);
        if(now == v) break;
        now = path[now][v];
    }
    printf("\n");
}
 
int floyd()
{
    For(k,1,N)
    {
        For(i,1,N)
        {
            For(j,1,N)
            {
                if(e[i][j] == e[i][k] + e[k][j] + fee[k])
                {
                    if(path[i][j] > path[i][k])//找到字典序最小的路***
                        path[i][j] = path[i][k];//按字典序更新道路
                }
                if(e[i][j] > e[i][k] + e[k][j] + fee[k])
                {
                    e[i][j] = e[i][k] + e[k][j] + fee[k];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
    return 0;
}
 
int main()
{
    while(scanf("%d",&N),N)
    {
        For(i,1,N)
        {
            For(j,1,N)
            {
                scanf("%d",&e[i][j]);
                if(e[i][j] == -1) e[i][j] = path[i][j] = 0x3f3f3f3f;
                else path[i][j] = j;
            }
        }
        For(i,1,N) scanf("%d",&fee[i]);
        floyd();
        int a, b;
        while(scanf("%d%d",&a,&b),a+b+2)
        {
            printf("From %d to %d :\n",a,b);
 
            bfs(a,b);
 
            printf("Total cost : %d\n\n",e[a][b]);
        }
    }
    return 0;
}