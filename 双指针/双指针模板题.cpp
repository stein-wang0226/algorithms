#include <bits/stdc++.h>
#define LOCAL
//#define int long long
//给定两个升序排序的有序数组 A 和 B，以及一个目标值 x。
//数组下标从 0 开始。
//请你求出满足 A[i]+B[j]=x 的数对 (i,j)。
//应为升序 所以一个从头开始  一个从尾开始即可
using namespace std;
const int N=1e5+5;
int n,m,x,a[N],b[N];
signed main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
cin>>n>>m>>x;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=m;i++)cin>>b[i];
//模板
int ans=0;
 for (int i = 1, j = m ; i <= n; i ++ )
    {
        while (j > 0 && a[i] + b[j] > x) j -- ;
        if (j >= 0 && a[i] + b[j] == x) cout << i-1 << ' ' << j-1 << endl,ans++;
    }                                                          //   下标从0开始
    return 0;
}
