#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int v;
    int id;
}s[1000001];
int c[1000001];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
int lowbit(int i)
{
    return i&-i;
}
int update(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
    memset(s,0,sizeof(s));
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)
    {
        s[i].id=i;
        scanf("%d",&s[i].v);
    }
    sort(s+1,s+n+1,cmp);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        update(s[i].id,1);
        ans+=i-sum( s[i].id );
    }
    printf("%lld\n",ans);
    }
    return 0;
}