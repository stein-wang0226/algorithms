#include <bits/stdc++.h>

using namespace std;
long long dp[25][1<<10][11];
//dp[i][j][k] ，i为当前进行到的数位，j状态压缩，k要求的上升子序列的度
int k,bit[25];
int getnews(int x,int s)//更新状态
{
    for (int i=x;i<10;++i)
    if (s&1<<i) return (s^(1<<i)|(1<<x));//让x替换x位后的第一个数
    return s|(1<<x);//如果x最大，将x对应位变为1
}
int getnum(int s)//求出当前状态LIS的长度也就是1的个数
{
    int ret=0;
    while (s)
    {
        if (s&1)
        ret++;
        s>>=1;
    }
    return ret;
}
long long dfs (int pos,int s,bool e,bool z)
//pos表示处理过的位置，s表示LIS的状态，e表示是否到达边界，z表示前面的所有位是否全为0
{
    if (pos==-1) return getnum(s)==k;
    if (!e&&dp[pos][s][k]!=-1) return dp[pos][s][k];
    long long ans=0;
    int endd=e?bit[pos]:9;
    for (int i=0;i<=endd;++i)
    ans+=dfs(pos-1,(z&&i==0)?0:getnews(i,s),e&&i==endd,z&&(i==0));
    if (!e) dp[pos][s][k]=ans;
    return ans;
}
long long calc (long long n)
{
    int len=0;
    while (n)
    {
        bit[len++]=n%10;
        n/=10;
    }
    return dfs(len-1,0,1,1);
}
int main()
{
    //freopen("de.txt","r",stdin);
    int t;
    long long l,r;
    memset(dp,-1,sizeof dp);
    scanf("%d",&t);
    int casee=0;
    while (t--)
    {
        scanf("%I64d%I64d%d",&l,&r,&k);
        printf("Case #%d: ",++casee);
        printf("%I64d\n",calc(r)-calc(l-1));
    }
    return 0;
}