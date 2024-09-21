#include <bits/stdc++.h>
//cf 489f dsu
// //# pragma GCC optimize(3)
// 题意：给定n个数的a数组。q次操作。每次操作有两种方式：1，对区间 
//  间的每个数进行如下处理，将该数变成该数的每位数之和。2，询问 
//  的值。

// 分析：可以发现将每个数最后都会收敛到小于10的值，因此，将所有数操作到收敛于小于10的次数不会太多。但是如果每次都遍历
// 必然会超时，由于每个数操作次数小的性质，当我们将它收敛于10以下后，如果区间修改还有这个数，是没有必要再遍历一次的。所以可以用set去维护还需要去操作的数的下标，或者DSU去维护这个数的下一个节点是谁。
#define int long long
#define endl "\n"
using namespace std;

const int N = 2e5 + 5;
int T, n,m,t;
int p[N],a[N]; //
int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
void Grainrain()
{
    int n,q;
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n+10;i++)p[i]=i;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    while(q--)
    {
        int type;
        scanf("%lld",&type);
        if(type==1)
        {
            int l,r;
            scanf("%lld%lld",&l,&r);
            for(int i=l;i<=r;i++)
            {
                i=find(i);
                if(i>r)break;
                int temp=a[i];
                int sum=0;
                while(temp)
                {
                    sum+=temp%10;
                    temp/=10;
                }
                a[i]=sum;
                if(a[i]<=9)
                {
                    if(find(i)!=find(i+1))
                        p[find(i)]=find(i+1);
                }
            }
        }
        else
        {
            int x;
            scanf("%lld",&x);
            printf("%lld\n",a[x]);
        }
    }
}