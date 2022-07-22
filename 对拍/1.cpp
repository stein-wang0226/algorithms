#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=22;
int n,vis[N],a[N];
int flag[55],isp[55];///isp[i]是记录i是否为素数的数组
void is_prime()///素数打表
{
    int k=0;
    memset(isp,0,sizeof(isp));
    memset(flag,0,sizeof(0));
    for(int i=2; i<=7; i++)
        if(!flag[i])
            for(int j=i*i; j<=50; j+=i)
                flag[j]=1;
    for(int i=2; i<=50; i++)
        if(!flag[i])
            isp[i]=1;
}
void init()///初始化
{
    for(int i=0; i<N; i++)
        a[i]=i+1;
}
void dfs(int x)
{
    if(x==n&&isp[a[0]+a[n-1]])///每个数都用到且首位元素和为素数
    {
        printf("%d",a[0]);
        for(int i=1; i<n; i++)
            printf(" %d",a[i]);
        printf("\n");
    }
    else
        for(int i=2; i<=n; i++) ///尝试放每个数
        {
            if(!vis[i]&&isp[i+a[x-1]])///若i没用过且与前一个数的和为素数
            {
                a[x]=i;///储存这个数
                vis[i]=1;
                dfs(x+1);
                vis[i]=0;
            }
        }
}
int main()
{
    is_prime();
    int k=0;
    while(~scanf("%d",&n))
    {
        init();
        printf("Case %d:\n",++k);
        memset(vis,0,sizeof(vis));
        dfs(1);
        printf("\n");
    }
    return 0;
}

