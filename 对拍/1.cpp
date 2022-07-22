#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=22;
int n,vis[N],a[N];
int flag[55],isp[55];///isp[i]�Ǽ�¼i�Ƿ�Ϊ����������
void is_prime()///�������
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
void init()///��ʼ��
{
    for(int i=0; i<N; i++)
        a[i]=i+1;
}
void dfs(int x)
{
    if(x==n&&isp[a[0]+a[n-1]])///ÿ�������õ�����λԪ�غ�Ϊ����
    {
        printf("%d",a[0]);
        for(int i=1; i<n; i++)
            printf(" %d",a[i]);
        printf("\n");
    }
    else
        for(int i=2; i<=n; i++) ///���Է�ÿ����
        {
            if(!vis[i]&&isp[i+a[x-1]])///��iû�ù�����ǰһ�����ĺ�Ϊ����
            {
                a[x]=i;///���������
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

