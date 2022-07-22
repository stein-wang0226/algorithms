//给一个无向图 ， 每条边可以是online边也可以是offline边，问
//有多少种方法使得每个节点的online边和offline边一样多
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAX = 110 ;
int on[MAX] , off[MAX];
int x[MAX] , y[MAX] ;
int degree[MAX] ;
int ans  ;
int n , m ;
void dfs(int num)
{
    if(num == m+1)//搜到num条边
    {
        for(int i = 1;i <= n;i++)
        if(on[i] != off[i])
        return ;


        ans++;return ;
    }
    int u = x[num] , v = y[num] ;
    if((on[u] < degree[u]/2) && (on[v] < degree[v]/2))
    {
        on[u]++;on[v]++;
        dfs(num+1);
        on[u]--;on[v]--;//回溯
    }
    if(off[v] < degree[v]/2 && off[u] < degree[u]/2)
    {
        off[u]++;off[v]++ ;
        dfs(num+1) ;
        off[u]--;off[v]-- ;//回溯
    }
}
int main()
{
    int T ;
    scanf("%d" ,&T) ;
    while(T--)
    {
        scanf("%d%d" ,&n , &m) ;
        memset(degree , 0 , sizeof(degree)) ;
        memset(on , 0 , sizeof(on)) ;
        memset(off,  0 , sizeof(off)) ;
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d" ,&x[i] ,&y[i]) ;
            degree[x[i]]++;
            degree[y[i]]++;
        }
        ans = 0 ;
        dfs(1);
        printf("%d\n" , ans) ;
    }
    return  0 ;
}